// glcontext.h
//
// Copyright (C) 2003, Chris Laurel <claurel@shatters.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

#ifndef _CELENGINE_GLCONTEXT_H_
#define _CELENGINE_GLCONTEXT_H_

#include <vector>
#include <string>

class GLContext
{
 public:
    GLContext() = default;
    virtual ~GLContext() = default;

    enum GLRenderPath
    {
        GLPath_GLSL              = 8,
    };

    void init(const std::vector<std::string>& ignoreExt);

    GLRenderPath getRenderPath() const { return renderPath; };
    bool setRenderPath(GLRenderPath);
    bool renderPathSupported(GLRenderPath) const;
    GLRenderPath nextRenderPath();

    bool extensionSupported(const std::string&) const;

    int getMaxTextures() const { return maxSimultaneousTextures; };
    bool hasMultitexture() const { return true; };
    bool bumpMappingSupported() const;

 private:
    GLRenderPath renderPath{ GLPath_GLSL };

    int maxSimultaneousTextures { 1 };
    std::vector<std::string> extensions;
};

#endif // _CELENGINE_GLCONTEXT_H_

