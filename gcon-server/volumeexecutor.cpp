#include "volumeexecutor.h"
#include <QDebug>
#include <alsa/asoundlib.h>

VolumeExecutor::VolumeExecutor()
{
}

void VolumeExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Volume execute";

    long min, max, volume, cur_vol;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";

    volume = jobj["volume"].toInt();

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);

    int err = snd_mixer_selem_set_playback_volume_all(elem, volume*max/100);

    qDebug()<<volume<<min<<max<<cur_vol<<err;

    snd_mixer_close(handle);
}
