#include "serverstate.h"
#include <alsa/asoundlib.h>

ServerState* ServerState::pInstance = 0;

ServerState::ServerState(): inhibit_id(0)
{
}

ServerState* ServerState::getInstance(){
    if(!pInstance)
        pInstance = new ServerState;
    return pInstance;
}

int ServerState::getVolumeLevel() {
    long min, max, lcur_vol;
    int cur_vol;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    snd_mixer_elem_t* elem;
    const char *card = "default";
    const char *selem_name = "Master";

    if (snd_mixer_open(&handle, 0) < 0) {
        qDebug()<<"Couldn't open sound mixer";
        snd_mixer_close(handle);
        return -1;
    }
    if (snd_mixer_attach(handle, card) < 0) {
        qDebug()<<"Couldn't snd mixer attach";
        snd_mixer_close(handle);
        return -1;
    }
    if (snd_mixer_selem_register(handle, NULL, NULL) < 0)  {
        qDebug()<<"Couldn't snd mixer register";
        snd_mixer_close(handle);
        return -1;
    }
    if (snd_mixer_load(handle) < 0) {
        qDebug()<<"Couldn't snd mixer load";
        snd_mixer_close(handle);
        return -1;
    }

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);

    elem = snd_mixer_find_selem(handle, sid);
    if (!elem) {
        qDebug()<<"Couldn't snd mixer find elem";
        snd_mixer_close(handle);
        return -1;
    }

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);

    if(snd_mixer_selem_get_playback_volume(elem, (snd_mixer_selem_channel_id_t)0, &lcur_vol) < 0) {
       snd_mixer_close(handle);
       qDebug()<<"Couldn't get current volume";
       return -1;
    }

    cur_vol = lcur_vol*100/max;

    snd_mixer_close(handle);
    return cur_vol;
}

uint ServerState::getInhibitId() {
    return inhibit_id;
}

void ServerState::setInhibitId(uint id){
    inhibit_id = id;
}
