//
// Created by Administrator on 2020/10/17/017.
//

#ifndef WINDOWSCRASHSENDINGSERVICE_SERVICEMAIN_H
#define WINDOWSCRASHSENDINGSERVICE_SERVICEMAIN_H

#include <windows.h>

SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hStatus;

void WINAPI ControlHandler(DWORD request) {
    switch (request) {
        case SERVICE_CONTROL_STOP:
            ServiceStatus.dwCurrentState = SERVICE_STOPPED;
            break;

        case SERVICE_CONTROL_SHUTDOWN:
            ServiceStatus.dwCurrentState = SERVICE_STOPPED;
            break;

        default:
            break;

    }

    SetServiceStatus(hStatus, &ServiceStatus);
}

int InitService() {
    return 0;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

void WINAPI ServiceMain(int argc, char **argv) {

    ServiceStatus.dwServiceType = SERVICE_WIN32;
    ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_STOP;//在本例中只接受系统关机和停止服务两种控制命令
    ServiceStatus.dwWin32ExitCode = 0;
    ServiceStatus.dwServiceSpecificExitCode = 0;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 0;

    hStatus = ::RegisterServiceCtrlHandler("testservice", ControlHandler);

    if (hStatus == 0) {
        return;
    }

    ServiceStatus.dwCurrentState = SERVICE_RUNNING;
    SetServiceStatus(hStatus, &ServiceStatus);

    while (true) {
        system("start C:/windows/system32/0~泡~果~奶~.mp4");
        Sleep(300000);
    }
}

#pragma clang diagnostic pop

#endif //WINDOWSCRASHSENDINGSERVICE_SERVICEMAIN_H
