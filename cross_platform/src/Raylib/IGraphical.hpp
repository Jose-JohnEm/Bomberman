/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

class IGraphical {
    public:

        /**
         * @brief Destroy the IGraphical object
         */
        virtual ~IGraphical() = default;

        /**
         * @brief Initialize window and OpenGL context
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        virtual void initWindow(int width, int height, const char *title) = 0;

        /**
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        virtual bool shouldCloseWindow() = 0;

        /**
         * @brief Close window
         */
        virtual void closeWindow() = 0;

        /**
         * @brief Set buffer to Draw textures
         */
        virtual void beginDrawing() = 0;

        /**
         * @brief Unset buffer to Draw textures
         */
        virtual void endDrawing() = 0;

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         */
        virtual void drawText(const char *text, int posX, int posY, int fontSize) = 0;

    protected:
    private:
};

#endif /* !IGRAPHICAL_HPP_ */
