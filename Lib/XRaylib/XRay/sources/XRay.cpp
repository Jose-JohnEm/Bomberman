/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"

XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    // Set resources
    setResources();

    // Scenes
    _scenesFunc.push_back(&XRay::displayMenuScene);
    _scenesFunc.push_back(&XRay::displayGameModeScene);
    _scenesFunc.push_back(&XRay::displayHowToPlayScene);
    _scenesFunc.push_back(&XRay::displaySettingsScene);
    _scenesFunc.push_back(&XRay::displayPlayerChoiceScene);
    _scenesFunc.push_back(&XRay::displayLoadGameScene);
    _scenesFunc.push_back(&XRay::displayInGameScene);
    _scenesFunc.push_back(&XRay::quitGame);

    // Display Intro (studio and introduction cinematic)
    _intro = std::make_pair(true, &XRay::displayStudio);
}

XRay::~XRay()
{
}

void XRay::setResources(void)
{
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::ADD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/add.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::REMOVE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/remove.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PREVIOUS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/previous.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/next.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::CONTROLS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/controls.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::GAMEPAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/gamepad.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HUMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/human.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::AI, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ai.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HEAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/head.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADSCENE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadScene.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BRANCH, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/branch.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/back.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HELP, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/help.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HELP_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/helpHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settings.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settingsHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::INDIE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/indie.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::STUDIO, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/studio.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_TEAM, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberTeam.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MENU_TITLE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/menuTitle.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_THINKING, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberThinking.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/play.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quit.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quitHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SKIP, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/skip.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SKIP_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/skipHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PARALLAX, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/parallax.png"))));
}

void XRay::quitGame(void)
{
    // Set scene
    _scene = END_GAME;
}

void XRay::displayStudio(void)
{
    // Draw
    for (int f = 0, x = 0, y = 0; x < 480; f += 1) {
        x = -100 + f;
        y = 1500 - f;
        beginDrawing();
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
		_resources.at(INDIE)->drawTexture(x, 440, Raylib::Color::White());
		_resources.at(STUDIO)->drawTexture(y, 440, Raylib::Color::White());
        endDrawing();
    }

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Intro is done, so update its status flag
    _intro.first = false;
    displayCinematic(Cinematic::INTRO);
}