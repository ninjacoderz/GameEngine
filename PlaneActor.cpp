//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#include "PlaneActor.h"

#include "Game.h"
#include "MeshComponent.h"

PlaneActor::PlaneActor(class Game *game) : Actor(game) {
    SetScale(10.0f);
    MeshComponent* meshComp = new MeshComponent(this);
    meshComp->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
}

PlaneActor::~PlaneActor() {
}
