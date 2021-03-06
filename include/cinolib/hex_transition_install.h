/********************************************************************************
*  This file is part of CinoLib                                                 *
*  Copyright(C) 2016: Marco Livesu                                              *
*                                                                               *
*  The MIT License                                                              *
*                                                                               *
*  Permission is hereby granted, free of charge, to any person obtaining a      *
*  copy of this software and associated documentation files (the "Software"),   *
*  to deal in the Software without restriction, including without limitation    *
*  the rights to use, copy, modify, merge, publish, distribute, sublicense,     *
*  and/or sell copies of the Software, and to permit persons to whom the        *
*  Software is furnished to do so, subject to the following conditions:         *
*                                                                               *
*  The above copyright notice and this permission notice shall be included in   *
*  all copies or substantial portions of the Software.                          *
*                                                                               *
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
*  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE *
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
*  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS *
*  IN THE SOFTWARE.                                                             *
*                                                                               *
*  Author(s):                                                                   *
*                                                                               *
*     Marco Livesu (marco.livesu@gmail.com)                                     *
*     http://pers.ge.imati.cnr.it/livesu/                                       *
*                                                                               *
*     Italian National Research Council (CNR)                                   *
*     Institute for Applied Mathematics and Information Technologies (IMATI)    *
*     Via de Marini, 6                                                          *
*     16149 Genoa,                                                              *
*     Italy                                                                     *
*********************************************************************************/
#ifndef CINO_HEX_TRANSITION_INSTALL_H
#define CINO_HEX_TRANSITION_INSTALL_H

#include <cinolib/meshes/meshes.h>
#include <cinolib/hex_transition.h>
#include <cinolib/octree.h>

namespace cinolib
{

/* This code serves to install a transition scheme in an adaptively refined grid,
 * in order to transform it into a pure hexahedral mesh. What the code does is to
 * merge coincident vertices and faces, and append the scheme elements to the mesh.
 *
 * WARNING: this code does not remove the older elements from the grid, which must
 * be removed a priori or afterwards.
*/

template<class M, class V, class E, class F, class P>
CINO_INLINE
void hex_transition_install(Polyhedralmesh<M,V,E,F,P> & m,
                            const HexTransition         type,
                            const vec3d               & center      = vec3d(0,0,0),
                            const double                scale       = 1.0,
                            const int                   orientation = PLUS_Y);

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// version that takes a pre-built octree (to avoid making one octree for each installation)
template<class M, class V, class E, class F, class P>
CINO_INLINE
void hex_transition_install(Polyhedralmesh<M,V,E,F,P> & m,
                            const Octree              & octree,
                            const HexTransition         type,
                            const vec3d               & center      = vec3d(0,0,0),
                            const double                scale       = 1.0,
                            const int                   orientation = PLUS_Y);
}

#ifndef  CINO_STATIC_LIB
#include "hex_transition_install.cpp"
#endif

#endif // CINO_HEX_TRANSITION_INSTALL_H
