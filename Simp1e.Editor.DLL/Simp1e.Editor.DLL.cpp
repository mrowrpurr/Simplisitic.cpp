#include <_Log_.h>
_LogToFile_("Simp1e.Editor.log");

#include <Simp1e/EntityPointerManagerClient.h>
#include <Simp1e/IEnvironmentManagerService.h>
#include <Simp1e/LabelComponent.h>
#include <Simp1e/ServiceHostClient.h>
#include <Simp1e/TextComponent.h>

#include <memory>

using namespace Simp1e;

constexpr auto* ENVIRONMENT_NAME = "Default";

std::unique_ptr<EntityPointerManagerClient> entityManager;

void CreateEntities() {
    auto label1 = entityManager->CreateEntity();
    entityManager->Add<TextComponent>(label1, "Hello from label 1");
    entityManager->Add<LabelComponent>(label1);

    auto label2 = entityManager->CreateEntity();
    entityManager->Add<TextComponent>(label2, "Hello from label 2");
    entityManager->Add<LabelComponent>(label2);
}

void Initialize(IEnvironment* environment) {
    entityManager = std::make_unique<EntityPointerManagerClient>(environment->GetEntityManager());
    CreateEntities();
}

OnSimp1eLoad {
    if (auto* environmentManagerService = Simp1eServices->GetService<IEnvironmentManagerService>())
        if (auto* environmentManager = environmentManagerService->GetEnvironmentManager())
            if (auto* environment = environmentManager->GetEnvironment(ENVIRONMENT_NAME)) Initialize(environment);
}

OnSimp1eStart {}
