/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "context.hpp"
#include "components/object.hpp"

namespace Materis {

    Object::Object() {


    }

    Object::~Object() {

        Materis::GetEngine()->renderer.getTextureRepository().freeByMesh(mesh.get());
    }

    void Object::init(const char* meshPath, const char* texturePath, float scale) {

        Tyra::ObjLoaderOptions objOptions;
        objOptions.scale = 200.0f;
        objOptions.flipUVs = true;

        auto data = Tyra::ObjLoader::load(Tyra::FileUtils::fromCwd(meshPath), objOptions);

        mesh = std::make_unique<Tyra::StaticMesh>(data.get());

        Materis::GetEngine()->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
    }

    void Object::update() {

        mesh->setPosition(position);
    }

    void Object::render(Tyra::StaticPipeline& pipeline, Tyra::StaPipOptions& renderOptions) {

        pipeline.render(mesh.get(), renderOptions);
    }
}