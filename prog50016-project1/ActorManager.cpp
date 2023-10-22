#include "ActorManager.h"
#include "GameTime.h"
#include <iostream>
#include <fstream>

ActorManager::~ActorManager() {
	Destroy();
}

void ActorManager::Initialize() {
	player = new Player();
	actorFactory = new ActorFactory();
	isReset = false;
	Load();
}

void ActorManager::Update(float deltaTime) {
	CalculateCollisions();
	player->Update(GameTime::Get().DeltaTime());
	SpawnEnemy(deltaTime);
	for (auto& actor : actors) {
		actor->Update(GameTime::Get().DeltaTime());
	}
	for (auto& laser : lasers) {
 		laser->Update(GameTime::Get().DeltaTime());
	}
	for (auto& actor : deletionStack) {
		actors.remove(actor);
		delete actor;
	}
	deletionStack.clear();
	for (auto& laser : laserDeletionStack) {
		lasers.remove(laser);
		delete laser;
	}
	laserDeletionStack.clear();
	if (isReset) {
		Destroy();
		Initialize();
	}
}

void ActorManager::Destroy() {
	for (auto& actor : actors) {
		delete actor;
	}
	actors.clear();
	for (auto& laser : lasers) {
		delete laser;
	}
	lasers.clear();
	delete player;
	player = nullptr;
	delete actorFactory;
	actorFactory = nullptr;
}

void ActorManager::CalculateCollisions() {
	for (auto& actor : actors) {
		player->Collide(actor);
	}
	for (auto& laser : lasers) {
		for (auto& actor : actors) {
			laser->Collide(actor);
		}
	}
}

void ActorManager::AddLaser(Laser* laser) {
	lasers.push_back(laser);
}

void ActorManager::RemoveLaser(Laser* laser) {
	laserDeletionStack.push_back(laser);
}

void ActorManager::AddActor(Actor* actor) {
	actors.push_back(actor);
}

void ActorManager::RemoveActor(Actor* actor) {
	deletionStack.push_back(actor);
}

void ActorManager::SpawnEnemy(float deltaTime) {
	asteroidCounter += deltaTime;
	asteroidBigCounter += deltaTime;
	enemyACounter += deltaTime;
	enemyBCounter += deltaTime;

	if (enemyACounter > enemyASpawnRate) {
		enemyACounter = 0;
		AddActor(actorFactory->GetEnemyA());
	}
	if (enemyBCounter > enemyBSpawnRate) {
		enemyBCounter = 0;
		AddActor(actorFactory->GetEnemyB());
	}
	if (asteroidCounter > asteroidSpawnRate) {
		asteroidCounter = 0;
		AddActor(actorFactory->GetAsteroid());
	}
	if (asteroidBigCounter > asteroidBigSpawnRate) {
		asteroidBigCounter = 0;
		AddActor(actorFactory->GetAsteroidBig());
	}
}

void ActorManager::SaveState(json::JSON& document) {

	document["asteroid"] = json::JSON::Make(json::JSON::Class::Array);
	document["asteroidBig"] = json::JSON::Make(json::JSON::Class::Array);
	document["enemyA"] = json::JSON::Make(json::JSON::Class::Array);
	document["enemyB"] = json::JSON::Make(json::JSON::Class::Array);
	document["enemyLaserA"] = json::JSON::Make(json::JSON::Class::Array);
	document["enemyLaserB"] = json::JSON::Make(json::JSON::Class::Array);
	document["laser"] = json::JSON::Make(json::JSON::Class::Array);
	document["player"] = json::JSON::Make(json::JSON::Class::Null);

	for (auto& actor : actors) {
		json::JSON actorOBJ = json::JSON::Make(json::JSON::Class::Null);
		actorOBJ["lives"] = actor->GetLives();
		actorOBJ["x"] = actor->GetPosition()[0];
		actorOBJ["y"] = actor->GetPosition()[1];
		actorOBJ["moveX"] = actor->GetMove()[0];
		actorOBJ["moveY"] = actor->GetMove()[1];
		if (actor->GetName() == "enemyLaserB") {
			actorOBJ["angle"] = ((EnemyLaserB*)actor)->GetAngle();
		}
		document[actor->GetName()].append(actorOBJ);
	}

	for (auto& laser : lasers) {
		json::JSON laserOBJ = json::JSON::Make(json::JSON::Class::Null);
		laserOBJ["x"] = laser->GetPosition()[0];
		laserOBJ["y"] = laser->GetPosition()[1];
		laserOBJ["moveX"] = laser->GetMove()[0];
		laserOBJ["moveY"] = laser->GetMove()[1];
		document[laser->GetName()].append(laserOBJ);
	}
	document[player->GetName()]["lives"] = player->GetLives();
	document[player->GetName()]["x"] = player->GetPosition()[0];
	document[player->GetName()]["y"] = player->GetPosition()[1];
}

void ActorManager::LoadState(json::JSON& document) {
	Destroy();
	Initialize();
	
	if (document.hasKey("asteroid")) {
		for (auto& obj : document["asteroid"].ArrayRange()) {
			Asteroid* a = actorFactory->GetAsteroid();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddActor(a);
		}
	}
	if (document.hasKey("asteroidBig")) {
		for (auto& obj : document["asteroidBig"].ArrayRange()) {
			AsteroidBig* a = actorFactory->GetAsteroidBig();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddActor(a);
		}
	}
	if (document.hasKey("enemyA")) {
		for (auto& obj : document["enemyA"].ArrayRange()) {
			EnemyA* a = actorFactory->GetEnemyA();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddActor(a);
		}
	}
	if (document.hasKey("enemyB")) {
		for (auto& obj : document["enemyB"].ArrayRange()) {
			EnemyB* a = actorFactory->GetEnemyB();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddActor(a);
		}
	}
	if (document.hasKey("enemyLaserA")) {
		for (auto& obj : document["enemyLaserA"].ArrayRange()) {
			EnemyLaserA* a = actorFactory->GetEnemyLaserA();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddActor(a);
		}
	}
	if (document.hasKey("enemyLaserB")) {
		for (auto& obj : document["enemyLaserB"].ArrayRange()) {
			EnemyLaserB* a = actorFactory->GetEnemyLaserB();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			a->SetAngle(obj["angle"].ToFloat());
			AddActor(a);
		}
	}
	if (document.hasKey("laser")) {
		for (auto& obj : document["laser"].ArrayRange()) {
			Laser* a = actorFactory->GetLaser();
			a->SetLives(obj["lives"].ToInt());
			a->SetPosition(
				obj["x"].ToFloat(),
				obj["y"].ToFloat()
			);
			a->SetMove(
				obj["moveX"].ToFloat(),
				obj["moveY"].ToFloat()
			);
			AddLaser(a);
		}
	}
	if (document.hasKey("player")) {
		player->SetLives(document["player"]["lives"].ToInt());
		player->SetPosition(
			document["player"]["x"].ToFloat(),
			document["player"]["y"].ToFloat()
		);
	}
}

void ActorManager::Load() {
	player->Load();

	std::ifstream inputStream("Data/SpawnRates.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("asteroid")) {
		asteroidSpawnRate = document["asteroid"].ToFloat();
	}
	if (document.hasKey("asteroidBig")) {
		asteroidBigSpawnRate = document["asteroidBig"].ToFloat();
	}
	if (document.hasKey("enemyShipA")) {
		enemyASpawnRate = document["enemyShipA"].ToFloat();
	}
	if (document.hasKey("enemyShipB")) {
		enemyBSpawnRate = document["enemyShipB"].ToFloat();
	}

}