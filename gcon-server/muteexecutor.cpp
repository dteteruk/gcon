#include "muteexecutor.h"
#include <QDebug>
#include <alsa/asoundlib.h>

MuteExecutor::MuteExecutor()
{
}

void MuteExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Mute execute";
    long min, max, volume, cur_vol;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume(elem, snd_mixer_selem_channel_id_t(0), &cur_vol);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);

    volume = (cur_vol > 0) ? 0 : 0.8*max;
    int err = snd_mixer_selem_set_playback_volume_all(elem, volume);

    qDebug()<<volume<<min<<max<<cur_vol<<err;

    snd_mixer_close(handle);
}
