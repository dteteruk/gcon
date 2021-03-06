#include "volumeexecutor.h"
#include <QDebug>
#include <alsa/asoundlib.h>

VolumeExecutor::VolumeExecutor()
{
}

void VolumeExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Volume execute";
    long min, max, volume;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    snd_mixer_elem_t* elem;
    const char *card = "default";
    const char *selem_name = "Master";

    volume = jobj["volume"].toInt();

    if (snd_mixer_open(&handle, 0) < 0) {
        qDebug()<<"Couldn't open sound mixer";
        snd_mixer_close(handle);
        return;
    }
    if (snd_mixer_attach(handle, card) < 0) {
        qDebug()<<"Couldn't snd mixer attach";
        snd_mixer_close(handle);
        return;
    }
    if (snd_mixer_selem_register(handle, NULL, NULL) < 0)  {
        qDebug()<<"Couldn't snd mixer register";
        snd_mixer_close(handle);
        return;
    }
    if (snd_mixer_load(handle) < 0) {
        qDebug()<<"Couldn't snd mixer load";
        snd_mixer_close(handle);
        return;
    }

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);

    elem = snd_mixer_find_selem(handle, sid);
    if (!elem) {
        qDebug()<<"Couldn't snd mixer find elem";
        snd_mixer_close(handle);
        return;
    }

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);

    int err = snd_mixer_selem_set_playback_volume_all(elem, volume*max/100);

    qDebug()<<volume<<min<<max<<err;

    snd_mixer_close(handle);
}
