#ifndef SERVERSTATE_H
#define SERVERSTATE_H

#include <QDebug>

class ServerState
{
public:
    static ServerState* getInstance();

    int getVolumeLevel();
    void setInhibitId(uint id);
    uint getInhibitId();

private:
    ServerState();
    ServerState( const ServerState& );
    ServerState& operator=( ServerState& );
    static ServerState* pInstance;

    uint inhibit_id;


};

#endif // SERVERSTATE_H
