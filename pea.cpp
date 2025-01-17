#include "pea.h"
#include "zombie.h"
#include "plant.h"
Pea::Pea(int xp, int yp, Parameters::Peatype type, Game* gm, BackGround* bkg, int row,int mxx)
	:Unit(xp, yp, gm, bkg, 1), MAX_X(mxx), move_step_(Parameters::PEA_MOVE_STEP) {
	BULLETTYPE = type;
	name_ = "pea"; row_ = row;
}
void Pea::Update() {
	if (x_ >= MAX_X)Removed();
	x_ += move_step_;
	printf("pea at %d, row %d\n", x_, row_);
	Attack();
}
void Pea::Attack() {
	auto info = bkg_->FindMinZombie(x_, row_);
	if (info.second == nullptr)return;
	if (info.first < x_) {
		dynamic_cast<Zombie*>(info.second)->DeduceLife(FIRE,BULLETTYPE);
		printf("image status is now %d\n", 1);
		image_status_ = 1;
		Removed();
	}
}