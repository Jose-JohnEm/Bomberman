/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera3D
*/

<<<<<<< HEAD
inline ::Camera3D Raylib::Camera3D::getCStruct() const
=======
inline ::Camera3D Raylib::Camera3D::getCStruct(void) const
>>>>>>> release/v0.3
{
    return _camera3D;
}

inline Raylib::Camera3D &Raylib::Camera3D::operator=(const Raylib::Camera3D &camera)
{
    set(camera);
    return *this;
}

inline void Raylib::Camera3D::set(const ::Camera3D &camera)
{
    _camera3D = camera;
}

inline void Raylib::Camera3D::set(const Raylib::Camera3D &camera)
{
    _camera3D = camera._camera3D;
}

<<<<<<< HEAD
inline void Raylib::Camera3D::beginMode3D(Raylib::Camera3D const &camera) const
{
    return ::BeginMode3D(camera.getCStruct());
=======
inline void Raylib::Camera3D::beginMode3D(void) const
{
    return ::BeginMode3D(_camera3D);
>>>>>>> release/v0.3
}

inline void Raylib::Camera3D::endMode3D(void) const
{
    return ::EndMode3D();
}

<<<<<<< HEAD
inline void Raylib::Camera3D::setCameraMode(Raylib::Camera3D const &camera, int const &mode) const
{
    return ::SetCameraMode(camera.getCStruct(), mode);
}

inline void Raylib::Camera3D::updateCamera(Raylib::Camera3D *camera) const
{
    ::Camera c_dst = camera->getCStruct();

    return ::UpdateCamera(&c_dst);
=======
inline void Raylib::Camera3D::setCameraMode(int const &mode) const
{
    return ::SetCameraMode(_camera3D, mode);
}

inline void Raylib::Camera3D::updateCamera(void)
{
    return ::UpdateCamera(&_camera3D);
}

inline void Raylib::Camera3D::setPosition(const Vector3 &position)
{
    _camera3D.position = position.getCStruct();
>>>>>>> release/v0.3
}

inline void Raylib::Camera3D::setCameraPanControl(int const &keyPan) const
{
    return ::SetCameraPanControl(keyPan);
}

<<<<<<< HEAD
void Raylib::Camera3D::setCameraAltControl(int const &keyAlt) const
=======
inline void Raylib::Camera3D::setCameraAltControl(int const &keyAlt) const
>>>>>>> release/v0.3
{
    return ::SetCameraAltControl(keyAlt);
}

<<<<<<< HEAD
void Raylib::Camera3D::setCameraSmoothZoomControl(int const &keySmoothZoom) const
=======
inline void Raylib::Camera3D::setCameraSmoothZoomControl(int const &keySmoothZoom) const
>>>>>>> release/v0.3
{
    return ::SetCameraSmoothZoomControl(keySmoothZoom);
}

<<<<<<< HEAD
void Raylib::Camera3D::setCameraMoveControls(int const &frontKey, int const &backKey, int const &rightKey, int const &leftKey, int const &upKey, int const &downKey) const
=======
inline void Raylib::Camera3D::setCameraMoveControls(int const &frontKey, int const &backKey, int const &rightKey, int const &leftKey, int const &upKey, int const &downKey) const
>>>>>>> release/v0.3
{
    return ::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
}

<<<<<<< HEAD
Ray Raylib::Camera3D::getMouseRay(::Vector2 const &mousePosition, Camera3D const &camera) const
{
    return ::GetMouseRay(mousePosition, camera.getCStruct());
}

Matrix Raylib::Camera3D::getCameraMatrix(Camera3D const &camera) const
{
    return ::GetCameraMatrix(camera.getCStruct());
}

::Vector2 Raylib::Camera3D::getWorldToScreen(Vector3 const &position, Camera3D const &camera) const
{
    return ::GetWorldToScreen(position.getCStruct(), camera.getCStruct());
}

::Vector2 Raylib::Camera3D::getWorldToScreenEx(Vector3 const &position, Camera3D const &camera, int const &width, int const &height) const
{
    return ::GetWorldToScreenEx(position.getCStruct(), camera.getCStruct(), width, height);
}

void Raylib::Camera3D::drawBillboard(Camera3D const &camera, Texture2D const &texture, Vector3 const &center, float const &size, Raylib::Color const &tint) const
{
    return ::DrawBillboard(camera.getCStruct(), texture, center.getCStruct(), size, tint.getCStruct());
}

void Raylib::Camera3D::drawBillboardRec(Camera3D const &camera, Texture2D const &texture,
Raylib::Rectangle const &source, Vector3 const &center, const float &size, Raylib::Color const &tint) const
{
    return ::DrawBillboardRec(camera.getCStruct(), texture, source.getCStruct(), center.getCStruct(), size, tint.getCStruct());
}
=======
inline Ray Raylib::Camera3D::getMouseRay(::Vector2 const &mousePosition) const
{
    return ::GetMouseRay(mousePosition, _camera3D);
}

inline Matrix Raylib::Camera3D::getCameraMatrix(void) const
{
    return ::GetCameraMatrix(_camera3D);
}

inline ::Vector2 Raylib::Camera3D::getWorldToScreen(Vector3 const &position) const
{
    return ::GetWorldToScreen(position.getCStruct(), _camera3D);
}

inline ::Vector2 Raylib::Camera3D::getWorldToScreenEx(Vector3 const &position, int const &width, int const &height) const
{
    return ::GetWorldToScreenEx(position.getCStruct(), _camera3D, width, height);
}

inline void Raylib::Camera3D::drawBillboard(Texture2D const &texture, Vector3 const &center, float const &size, Raylib::Color const &tint) const
{
    return ::DrawBillboard(_camera3D, texture, center.getCStruct(), size, tint.getCStruct());
}

inline void Raylib::Camera3D::drawBillboardRec(Texture2D const &texture,
Raylib::Rectangle const &source, Vector3 const &center, const float &size, Raylib::Color const &tint) const
{
    return ::DrawBillboardRec(_camera3D, texture, source.getCStruct(), center.getCStruct(), size, tint.getCStruct());
}
>>>>>>> release/v0.3
