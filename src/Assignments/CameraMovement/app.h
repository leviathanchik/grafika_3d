#pragma once

#include <vector>


#include "Application/application.h"
#include "Application/utils.h"

#include "glad/gl.h"
#include "glm/glm.hpp"
#include "camera.h"

class SimpleShapeApplication : public xe::Application
{
public:
    SimpleShapeApplication(int width, int height, std::string title, bool debug) : Application(width, height, title, debug) {}

    void init() override;;

    void frame() override;

    void framebuffer_resize_callback(int w, int h) override;

    void set_camera(Camera *camera) { this->camera_ = camera; }
    Camera *camera() { return this->camera_; }
    ~SimpleShapeApplication() {
        if (this->camera_) {
            delete this->camera_;
        }
    }

    void scroll_callback(double xoffset, double yoffset) override;

private:
    Camera *camera_;
    GLuint vao_;

    GLuint u_pvm_buffer_;
};