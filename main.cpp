#include <entt.hpp>
#include <iostream>

int main()
{
    entt::registry registry;
    const auto entity = registry.create();
    registry.emplace<int>(entity, 50);

    const auto entity2 = registry.create();
    registry.emplace<int>(entity2, 50);

    const auto entity3 = registry.create();
    registry.emplace<float>(entity3);

    const auto group = registry.group<int>();

    for (auto entity : group)
    {
        std::cout << "Entity: " << (int) entity << std::endl;
    }
    
    return 0;
}
