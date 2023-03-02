#include "CollisionManager.h"
#include "PlayState.h"
#include "Game.h"
void CollisionManager::checkCollision(Entity* ast, Entity* ent) {
	Transform* astTr = ast->getComponent<Transform>(TRANSFORM_H);
	Transform* entTr = ent->getComponent<Transform>(TRANSFORM_H);

	if (Collisions::collidesWithRotation(astTr->getPos(), astTr->getW(), astTr->getH(), astTr->getR(), entTr->getPos(), entTr->getW(), entTr->getH(), entTr->getR())) {
		if (ent->hasComponent(FIGHTERCONTROL_H)) {
			for (auto& e : mngr_->getEntities()) {
				if (e->hasGroup(_grp_ASTEROIDS) || e->hasGroup(_grp_BULLETS)) {
					e->setAlive(false);
				}
			}
			Health* health = ent->getComponent<Health>(HEALTH_H);
			if (health->getLifes() > 1) {
				health->quitLife();
				astMnrg_->createAsteroids(10);
				entTr->setPos(Vector2D(WIN_WIDTH / 2 - entTr->getW() / 2, WIN_HEIGHT / 2 - entTr->getH() / 2));
				entTr->setVel(Vector2D(0, 0));
				entTr->setR(0);
			}
			else {
				static_cast<PlayState*>(mngr_)->getGame()->returnToMainMenu(static_cast<PlayState*>(mngr_)->getGame());
			}
		}
		else {
			ent->setAlive(false);
			astMnrg_->onCollision(ast);
		}
	}
}