/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "context.hpp"
#include "components/entity.hpp"
#include <functional>

namespace Materis {

    Entity::Entity() {

    }

    Entity::~Entity() {

        Materis::GetEngine()->renderer.getTextureRepository().freeByMesh(mesh.get());
    }

    void Entity::init(const char* meshPath, const char* texturePath, float scale) {

        Tyra::MD2LoaderOptions MD2Options;
        MD2Options.scale = scale;
        MD2Options.flipUVs = true;

        auto data = Tyra::MD2Loader::load(Tyra::FileUtils::fromCwd(meshPath), MD2Options);

        mesh = std::make_shared<Tyra::DynamicMesh>(data.get());
        mesh->animation.speed = 0.2f;
        mesh->rotation.rotateX(-1.566f);
        mesh->rotation.rotateY(1.566f);

        Materis::GetEngine()->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
    }

    void Entity::update() {

        mesh->setPosition(position);
        mesh->update();
    }

    void Entity::render(Tyra::DynamicPipeline& pipeline, Tyra::DynPipOptions& dynpipOptions) {
        
        pipeline.render(mesh.get(), dynpipOptions);
    }

    void Entity::setAnimation(Materis::Animation& animation) {

        mesh->animation.loop = animation.loop;
        mesh->animation.setSequence(animation.framesSequence);
        mesh->animation.setCallback(
            std::bind(&Materis::Animation::animationCallback, &animation, std::placeholders::_1));
    }

    std::shared_ptr<Tyra::DynamicMesh>& Entity::getMesh() {

        return mesh;
    }

}