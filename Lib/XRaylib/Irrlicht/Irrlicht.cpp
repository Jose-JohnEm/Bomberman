/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Irrlicht
*/

#include "Irrlicht.hpp"

Irrlicht::Irrlicht()
{
    _device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 32, false, true, false, 0);
    _device->setWindowCaption(L"Bomberman");

    _driver = _device->getVideoDriver();
    _sceneManager = _device->getSceneManager();

    _sceneManager->addCameraSceneNode (0, irr::core::vector3df (0,0,0), irr::core::vector3df (5,0,0));

    _scenesFunc.push_back(&Irrlicht::displayMenu);
    _intro = std::make_pair(true, &Irrlicht::displayIntro);
}

Irrlicht::~Irrlicht()
{
    _device->drop();
}

void Irrlicht::displayOpening(void) // TODO: To change ?
{
    irr::ITimer *timer = _device->getTimer();
    std::string path;
    int i = 1;

    for (std::string str = "001"; str != "321";) {
        path = "resources/cinematic/png/ezgif-frame-" + str + ".png";
        irr::video::ITexture *frame = _driver->getTexture(path.c_str());
        _driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        _driver->draw2DImage(frame, irr::core::position2d<irr::s32>(0, 0));
        _driver->endScene();
        i++;
        if (i < 10)
            str = "00" + std::to_string(i);
        else if (i < 100)
            str = "0" + std::to_string(i);
        else
            str = std::to_string(i);
//    for (double t = timer->getRealTime(); timer->getRealTime() - t < 40;);
    }
}

void Irrlicht::displayIntro(void) // TODO: To change ?
{
    irr::ITimer *timer = _device->getTimer();
    irr::u32 startTime = timer->getRealTime();
    irr::video::ITexture *indie = _driver->getTexture("resources/assets/indieTitle.png");
    irr::video::ITexture *studio = _driver->getTexture("resources/assets/studioTitle.png");

    _scene = INTRO;
    for (int f = 0, x = 0, y = 0; timer->getRealTime() - startTime < 4100; f += 2) {
        x = -100 + f;
        y = 1500 - f;
        _driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
        _driver->draw2DImage(studio, irr::core::position2d<irr::s32>(y, 1080 / 2 - 100));
        _driver->draw2DImage(indie, irr::core::position2d<irr::s32>(x, 1080 / 2 - 100));
        _driver->endScene();
    }
    while (timer->getRealTime() - startTime < 6200);
    _intro.first = false;
    displayOpening();
}

void Irrlicht::displayMenu(void) // TODO: To change ?
{
    irr::gui::ICursorControl *cursor;
    irr::video::ITexture *head = _driver->getTexture("resources/assets/head.png");
    irr::video::ITexture *title = _driver->getTexture("resources/assets/title.png");
//    const irr::SEvent* event;

//    _driver->makeColorKeyTexture(head, irr::core::position2d<irr::s32>(0,0));
//    _driver->makeColorKeyTexture(title, irr::core::position2d<irr::s32>(0,0));
//    _driver->makeColorKeyTexture(title, irr::video::SColor(0,0,0,0));
//    _driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
//    _driver->getMaterial2D().AntiAliasing=irr::video::EAAM_FULL_BASIC;

    if (_intro.first == true)
        (this->*_intro.second)();
//    _scene = MAIN_MENU;
    _driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
    if (_device->getCursorControl()->isVisible() == true)
        _device->getCursorControl()->setVisible(false);
    _driver->enableMaterial2D();
    _driver->draw2DImage(title, irr::core::position2d<irr::s32>(1920 / 4, 40));
    _driver->draw2DImage(head, irr::core::position2d<irr::s32>(_device->getCursorControl()->getPosition().X, _device->getCursorControl()->getPosition().Y));
    _driver->enableMaterial2D(false);
    _sceneManager->drawAll();
    _driver->endScene();
}

void Irrlicht::initWindow(const int &width, const int &height, const std::string &title) const
{
}

bool Irrlicht::shouldCloseWindow(void) const
{
    return !(_device->run() && _driver);
}

void Irrlicht::closeWindow(void) const
{
}

void Irrlicht::drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) const
{
}

void Irrlicht::drawTextFont(const std::string &text, const int &posX, const int &posY, const int &fontSize, const std::string &font, const std::string &color) const
{
}

void Irrlicht::beginDrawing(void) const
{
}

void Irrlicht::endDrawing(void) const
{
}

void Irrlicht::display(void)
{
    (this->*_scenesFunc[_scene])();
}

bool Irrlicht::isInGameScene(void) const
{
    return false;
}

void Irrlicht::setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info)
{
    // TODO: Implement this function
}

void Irrlicht::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

void Irrlicht::setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

void Irrlicht::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    // TODO: Implement this function
}

const std::vector<std::string> &Irrlicht::getUserNames(void) const
{
    // TODO: Implement this function
    return _userNames;
}

IGraphical::Scene Irrlicht::getScene(void) const
{
    // TODO: Implement this function
    return _scene;
}

void Irrlicht::setScene(const Scene &scene)
{
    // TODO: Implement this function
}
