/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.inl
*/

inline Vector3 Raylib::Vector3::operator=(const Vector3 &copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;
    
    return Vector3(copy);
}

inline Vector3 Raylib::Vector3::operator=(const ::Vector3 &cvec)
{
    this->x = cvec.x;
    this->y = cvec.y;
    this->z = cvec.z;
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;

    return Vector3(cvec);
}

inline ::Vector3 Raylib::Vector3::getCStruct()
{
    _vector.x = this->x;
    _vector.y = this->y;
    _vector.z = this->z;

    return _vector;
}