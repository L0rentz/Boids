#ifndef CORE_HPP_
#define CORE_HPP_

#include "stb_image.h"
#include "Boid.hpp"
#include "Exception.hpp"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include <SFML/Graphics.hpp>
#include <time.h>
#include <map>
#include <fstream>

#ifdef _WIN32
    #define SHADER_PATH "../../src/"
#else
    #define SHADER_PATH "src/"
#endif

class Core {
    public:
        Core();
        ~Core();

        void run();

    protected:
    private:
        void events();
        void display();
        void update();
        void updateHashtable();

        sf::Window _window;
        int _framerate;
        sf::Event _event;
        bool _running;
        sf::Clock _runTime;
        double _lastTime;
        double _currentTime;

        Boid *_boids;
        float *_sharedBuffer;
        unsigned int _bufferSize;
        unsigned int _tableSize;
        unsigned int _worldPosScaleAngleDegSize;
        unsigned int _worldPosScaleAngleDegIdx1;
        unsigned int _worldPosScaleAngleDegIdx2;
        unsigned int _worldPosScaleAngleDegOffset;
        unsigned int _metadataSize;
        unsigned int _bufferSelectorIdx;

        // For OpenGL
        const char *getFileContent(const std::string &path) const;
        void compileShader(unsigned int *shaderId, std::string filename, unsigned int type);
        void checkShaderProgramCompileError(unsigned int shaderProgramId);
        void openGlInit();
        void openGlDraw();

        bool _wireframe;
        unsigned int _VAO, _VBO, _instanceVBO, _SSBO;
        unsigned int _vertexFragProgram;
        unsigned int _computeProgramFlocking, _computeProgramHashing;
        unsigned int _vertexShader;
        unsigned int _computeShader;
        unsigned int _fragmentShader;
        glm::mat4 _projection;
};

#endif /* !CORE_HPP_ */
