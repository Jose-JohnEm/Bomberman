/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.inl
*/

inline Vector4 Raylib::Vector4::operator=(const Vector4 &copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;
    _vector.w = this->w;
    
    return Vector4(copy);
}

inline Vector4 Raylib::Vector4::operator=(const ::Vector4 &cvec)
{
    this->x = cvec.x;
    this->y = cvec.y;
    this->z = cvec.z;
    this->w = cvec.w;
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;
    _vector.w = this->w;

    return Vector4(cvec);
}

inline ::Vector4 Raylib::Vector4::getCStruct()
{
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;
    _vector.w = this->w;

    return _vector;
}