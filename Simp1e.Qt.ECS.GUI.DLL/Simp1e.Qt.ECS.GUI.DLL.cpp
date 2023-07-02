#include <_Log_.h>
_LogToFile_("Simp1e.Qt.ECS.GUI.log");

#include <Simp1e/ComponentCast.h>
#include <Simp1e/DefineSystemType.h>
#include <Simp1e/EntityPointerManagerClient.h>
#include <Simp1e/IEnvironmentManagerService.h>
#include <Simp1e/LabelComponent.h>
#include <Simp1e/QMainWindowComponent.h>
#include <Simp1e/QtGUISystem.h>
#include <Simp1e/ServiceHostClient.h>
#include <Simp1e/SystemPointerManagerClient.h>
#include <Simp1e/TextComponent.h>
#include <Simp1e/WindowComponent.h>

#include <QApplication>
#include <QTimer>
#include <chrono>
#include <memory>

using namespace Simp1e;

int          argc = 0;
QApplication app{argc, nullptr};

constexpr auto* ENVIRONMENT_NAME = "Default";

IEnvironment*                               _environment;
std::unique_ptr<SystemPointerManagerClient> systemManager;
std::unique_ptr<EntityPointerManagerClient> entityManager;

QTimer                                                      mainLoopTimer;
int                                                         mainLoopPerMillisecond = 1000;  // 16;
std::chrono::time_point<std::chrono::high_resolution_clock> mainLoopLastTime =
    std::chrono::high_resolution_clock::now();

void GameLoop() {
    _Log_("GameLoop");

    auto currentTime = std::chrono::high_resolution_clock::now();
    auto deltaTime   = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - mainLoopLastTime).count();
    mainLoopLastTime = currentTime;
    auto seconds     = deltaTime / 1000000.0;

    _environment->GetSystemManager()->Update(_environment, seconds);

    _Log_("GameLoop end");
}

void SetupSystems(IEnvironment* environment) { systemManager->Add<QtGUISystem>(environment); }

void Initialize(IEnvironment* environment) {
    _environment  = environment;
    systemManager = std::make_unique<SystemPointerManagerClient>(environment->GetSystemManager());
    entityManager = std::make_unique<EntityPointerManagerClient>(environment->GetEntityManager());
    SetupSystems(environment);
}

OnSimp1eLoad {
    _Log_("Init");
    if (auto* environmentManagerService = Simp1eServices->GetService<IEnvironmentManagerService>())
        if (auto* environmentManager = environmentManagerService->GetEnvironmentManager())
            if (auto* environment = environmentManager->GetEnvironment(ENVIRONMENT_NAME)) Initialize(environment);
}

OnSimp1eStart {
    _Log_("Qt ECS GUI start");

    QObject::connect(&mainLoopTimer, &QTimer::timeout, &app, GameLoop);
    mainLoopTimer.start(mainLoopPerMillisecond);

    _Log_("Run Qt application");
    app.setStyle("Fusion");
    app.exec();

    _Log_("Qt ECS GUI end");
}
