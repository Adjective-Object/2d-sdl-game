#ifndef ENGINE_GL_BRIDGE
#define ENGINE_GL_BRIDGE
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#ifndef __APPLE__
#include <GL/gl3.h>
#else
#include <OpenGL/gl3.h>
#endif

#include <iostream>

const char* glErrorString(GLenum error);

#define callWithGLCheck(NAME, ...) \
    NAME(__VA_ARGS__);             \
    CHECK_GL_ERROR(#NAME);

#define _glBindFramebuffer(...) callWithGLCheck(glBindFramebuffer, __VA_ARGS__)
#define _glBindTexture(...) callWithGLCheck(glBindTexture, __VA_ARGS__)
#define _glFlush(...) callWithGLCheck(glFlush, __VA_ARGS__)
#define _glFramebufferTexture2D(...) \
    callWithGLCheck(glFramebufferTexture2D, __VA_ARGS__)
#define _glTexImage2D(...) callWithGLCheck(glTexImage2D, __VA_ARGS__)
#define _glAccum(...) callWithGLCheck(glAccum, __VA_ARGS__)
#define _glActiveStencilFaceEXT(...) \
    callWithGLCheck(glActiveStencilFaceEXT, __VA_ARGS__)
#define _glActiveTexture(...) callWithGLCheck(glActiveTexture, __VA_ARGS__)
#define _glActiveTextureARB(...) \
    callWithGLCheck(glActiveTextureARB, __VA_ARGS__)
#define _glAlphaFunc(...) callWithGLCheck(glAlphaFunc, __VA_ARGS__)
#define _glAreTexturesResident(...) \
    callWithGLCheck(glAreTexturesResident, __VA_ARGS__)
#define _glArrayElement(...) callWithGLCheck(glArrayElement, __VA_ARGS__)
#define _glAttachObjectARB(...) callWithGLCheck(glAttachObjectARB, __VA_ARGS__)
#define _glAttachShader(...) callWithGLCheck(glAttachShader, __VA_ARGS__)
#define _glBegin(...) callWithGLCheck(glBegin, __VA_ARGS__)
#define _glBeginConditionalRender(...) \
    callWithGLCheck(glBeginConditionalRender, __VA_ARGS__)
#define _glBeginConditionalRenderNV(...) \
    callWithGLCheck(glBeginConditionalRenderNV, __VA_ARGS__)
#define _glBeginQuery(...) callWithGLCheck(glBeginQuery, __VA_ARGS__)
#define _glBeginQueryARB(...) callWithGLCheck(glBeginQueryARB, __VA_ARGS__)
#define _glBeginTransformFeedback(...) \
    callWithGLCheck(glBeginTransformFeedback, __VA_ARGS__)
#define _glBeginTransformFeedbackEXT(...) \
    callWithGLCheck(glBeginTransformFeedbackEXT, __VA_ARGS__)
#define _glBindAttribLocation(...) \
    callWithGLCheck(glBindAttribLocation, __VA_ARGS__)
#define _glBindAttribLocationARB(...) \
    callWithGLCheck(glBindAttribLocationARB, __VA_ARGS__)
#define _glBindBuffer(...) callWithGLCheck(glBindBuffer, __VA_ARGS__)
#define _glBindBufferARB(...) callWithGLCheck(glBindBufferARB, __VA_ARGS__)
#define _glBindBufferBase(...) callWithGLCheck(glBindBufferBase, __VA_ARGS__)
#define _glBindBufferBaseEXT(...) \
    callWithGLCheck(glBindBufferBaseEXT, __VA_ARGS__)
#define _glBindBufferOffsetEXT(...) \
    callWithGLCheck(glBindBufferOffsetEXT, __VA_ARGS__)
#define _glBindBufferRange(...) callWithGLCheck(glBindBufferRange, __VA_ARGS__)
#define _glBindBufferRangeEXT(...) \
    callWithGLCheck(glBindBufferRangeEXT, __VA_ARGS__)
#define _glBindFragDataLocation(...) \
    callWithGLCheck(glBindFragDataLocation, __VA_ARGS__)
#define _glBindFragDataLocationEXT(...) \
    callWithGLCheck(glBindFragDataLocationEXT, __VA_ARGS__)
#define _glBindFramebuffer(...) callWithGLCheck(glBindFramebuffer, __VA_ARGS__)
#define _glBindFramebufferEXT(...) \
    callWithGLCheck(glBindFramebufferEXT, __VA_ARGS__)
#define _glBindProgramARB(...) callWithGLCheck(glBindProgramARB, __VA_ARGS__)
#define _glBindRenderbuffer(...) \
    callWithGLCheck(glBindRenderbuffer, __VA_ARGS__)
#define _glBindRenderbufferEXT(...) \
    callWithGLCheck(glBindRenderbufferEXT, __VA_ARGS__)
#define _glBindTexture(...) callWithGLCheck(glBindTexture, __VA_ARGS__)
#define _glBindVertexArrayAPPLE(...) \
    callWithGLCheck(glBindVertexArrayAPPLE, __VA_ARGS__)
#define _glBitmap(...) callWithGLCheck(glBitmap, __VA_ARGS__)
#define _glBlendColor(...) callWithGLCheck(glBlendColor, __VA_ARGS__)
#define _glBlendColorEXT(...) callWithGLCheck(glBlendColorEXT, __VA_ARGS__)
#define _glBlendEquation(...) callWithGLCheck(glBlendEquation, __VA_ARGS__)
#define _glBlendEquationEXT(...) \
    callWithGLCheck(glBlendEquationEXT, __VA_ARGS__)
#define _glBlendEquationSeparate(...) \
    callWithGLCheck(glBlendEquationSeparate, __VA_ARGS__)
#define _glBlendEquationSeparateATI(...) \
    callWithGLCheck(glBlendEquationSeparateATI, __VA_ARGS__)
#define _glBlendEquationSeparateEXT(...) \
    callWithGLCheck(glBlendEquationSeparateEXT, __VA_ARGS__)
#define _glBlendFunc(...) callWithGLCheck(glBlendFunc, __VA_ARGS__)
#define _glBlendFuncSeparate(...) \
    callWithGLCheck(glBlendFuncSeparate, __VA_ARGS__)
#define _glBlendFuncSeparateEXT(...) \
    callWithGLCheck(glBlendFuncSeparateEXT, __VA_ARGS__)
#define _glBlitFramebuffer(...) callWithGLCheck(glBlitFramebuffer, __VA_ARGS__)
#define _glBlitFramebufferEXT(...) \
    callWithGLCheck(glBlitFramebufferEXT, __VA_ARGS__)
#define _glBufferData(...) callWithGLCheck(glBufferData, __VA_ARGS__)
#define _glBufferDataARB(...) callWithGLCheck(glBufferDataARB, __VA_ARGS__)
#define _glBufferParameteriAPPLE(...) \
    callWithGLCheck(glBufferParameteriAPPLE, __VA_ARGS__)
#define _glBufferSubData(...) callWithGLCheck(glBufferSubData, __VA_ARGS__)
#define _glBufferSubDataARB(...) \
    callWithGLCheck(glBufferSubDataARB, __VA_ARGS__)
#define _glCallList(...) callWithGLCheck(glCallList, __VA_ARGS__)
#define _glCallLists(...) callWithGLCheck(glCallLists, __VA_ARGS__)
#define _glCheckFramebufferStatus(...) \
    callWithGLCheck(glCheckFramebufferStatus, __VA_ARGS__)
#define _glCheckFramebufferStatusEXT(...) \
    callWithGLCheck(glCheckFramebufferStatusEXT, __VA_ARGS__)
#define _glClampColor(...) callWithGLCheck(glClampColor, __VA_ARGS__)
#define _glClampColorARB(...) callWithGLCheck(glClampColorARB, __VA_ARGS__)
#define _glClear(...) callWithGLCheck(glClear, __VA_ARGS__)
#define _glClearAccum(...) callWithGLCheck(glClearAccum, __VA_ARGS__)
#define _glClearBufferfi(...) callWithGLCheck(glClearBufferfi, __VA_ARGS__)
#define _glClearBufferfv(...) callWithGLCheck(glClearBufferfv, __VA_ARGS__)
#define _glClearBufferiv(...) callWithGLCheck(glClearBufferiv, __VA_ARGS__)
#define _glClearBufferuiv(...) callWithGLCheck(glClearBufferuiv, __VA_ARGS__)
#define _glClearColor(...) callWithGLCheck(glClearColor, __VA_ARGS__)
#define _glClearColorIiEXT(...) callWithGLCheck(glClearColorIiEXT, __VA_ARGS__)
#define _glClearColorIuiEXT(...) \
    callWithGLCheck(glClearColorIuiEXT, __VA_ARGS__)
#define _glClearDepth(...) callWithGLCheck(glClearDepth, __VA_ARGS__)
#define _glClearIndex(...) callWithGLCheck(glClearIndex, __VA_ARGS__)
#define _glClearStencil(...) callWithGLCheck(glClearStencil, __VA_ARGS__)
#define _glClientActiveTexture(...) \
    callWithGLCheck(glClientActiveTexture, __VA_ARGS__)
#define _glClientActiveTextureARB(...) \
    callWithGLCheck(glClientActiveTextureARB, __VA_ARGS__)
#define _glClientWaitSync(...) callWithGLCheck(glClientWaitSync, __VA_ARGS__)
#define _glClipPlane(...) callWithGLCheck(glClipPlane, __VA_ARGS__)
#define _glColor3b(...) callWithGLCheck(glColor3b, __VA_ARGS__)
#define _glColor3bv(...) callWithGLCheck(glColor3bv, __VA_ARGS__)
#define _glColor3d(...) callWithGLCheck(glColor3d, __VA_ARGS__)
#define _glColor3dv(...) callWithGLCheck(glColor3dv, __VA_ARGS__)
#define _glColor3f(...) callWithGLCheck(glColor3f, __VA_ARGS__)
#define _glColor3fv(...) callWithGLCheck(glColor3fv, __VA_ARGS__)
#define _glColor3i(...) callWithGLCheck(glColor3i, __VA_ARGS__)
#define _glColor3iv(...) callWithGLCheck(glColor3iv, __VA_ARGS__)
#define _glColor3s(...) callWithGLCheck(glColor3s, __VA_ARGS__)
#define _glColor3sv(...) callWithGLCheck(glColor3sv, __VA_ARGS__)
#define _glColor3ub(...) callWithGLCheck(glColor3ub, __VA_ARGS__)
#define _glColor3ubv(...) callWithGLCheck(glColor3ubv, __VA_ARGS__)
#define _glColor3ui(...) callWithGLCheck(glColor3ui, __VA_ARGS__)
#define _glColor3uiv(...) callWithGLCheck(glColor3uiv, __VA_ARGS__)
#define _glColor3us(...) callWithGLCheck(glColor3us, __VA_ARGS__)
#define _glColor3usv(...) callWithGLCheck(glColor3usv, __VA_ARGS__)
#define _glColor4b(...) callWithGLCheck(glColor4b, __VA_ARGS__)
#define _glColor4bv(...) callWithGLCheck(glColor4bv, __VA_ARGS__)
#define _glColor4d(...) callWithGLCheck(glColor4d, __VA_ARGS__)
#define _glColor4dv(...) callWithGLCheck(glColor4dv, __VA_ARGS__)
#define _glColor4f(...) callWithGLCheck(glColor4f, __VA_ARGS__)
#define _glColor4fv(...) callWithGLCheck(glColor4fv, __VA_ARGS__)
#define _glColor4i(...) callWithGLCheck(glColor4i, __VA_ARGS__)
#define _glColor4iv(...) callWithGLCheck(glColor4iv, __VA_ARGS__)
#define _glColor4s(...) callWithGLCheck(glColor4s, __VA_ARGS__)
#define _glColor4sv(...) callWithGLCheck(glColor4sv, __VA_ARGS__)
#define _glColor4ub(...) callWithGLCheck(glColor4ub, __VA_ARGS__)
#define _glColor4ubv(...) callWithGLCheck(glColor4ubv, __VA_ARGS__)
#define _glColor4ui(...) callWithGLCheck(glColor4ui, __VA_ARGS__)
#define _glColor4uiv(...) callWithGLCheck(glColor4uiv, __VA_ARGS__)
#define _glColor4us(...) callWithGLCheck(glColor4us, __VA_ARGS__)
#define _glColor4usv(...) callWithGLCheck(glColor4usv, __VA_ARGS__)
#define _glColorMask(...) callWithGLCheck(glColorMask, __VA_ARGS__)
#define _glColorMaskIndexedEXT(...) \
    callWithGLCheck(glColorMaskIndexedEXT, __VA_ARGS__)
#define _glColorMaski(...) callWithGLCheck(glColorMaski, __VA_ARGS__)
#define _glColorMaterial(...) callWithGLCheck(glColorMaterial, __VA_ARGS__)
#define _glColorPointer(...) callWithGLCheck(glColorPointer, __VA_ARGS__)
#define _glColorSubTable(...) callWithGLCheck(glColorSubTable, __VA_ARGS__)
#define _glColorSubTableEXT(...) \
    callWithGLCheck(glColorSubTableEXT, __VA_ARGS__)
#define _glColorTable(...) callWithGLCheck(glColorTable, __VA_ARGS__)
#define _glColorTableEXT(...) callWithGLCheck(glColorTableEXT, __VA_ARGS__)
#define _glColorTableParameterfv(...) \
    callWithGLCheck(glColorTableParameterfv, __VA_ARGS__)
#define _glColorTableParameteriv(...) \
    callWithGLCheck(glColorTableParameteriv, __VA_ARGS__)
#define _glCompileShader(...) callWithGLCheck(glCompileShader, __VA_ARGS__)
#define _glCompileShaderARB(...) \
    callWithGLCheck(glCompileShaderARB, __VA_ARGS__)
#define _glCompressedTexImage1D(...) \
    callWithGLCheck(glCompressedTexImage1D, __VA_ARGS__)
#define _glCompressedTexImage1DARB(...) \
    callWithGLCheck(glCompressedTexImage1DARB, __VA_ARGS__)
#define _glCompressedTexImage2D(...) \
    callWithGLCheck(glCompressedTexImage2D, __VA_ARGS__)
#define _glCompressedTexImage2DARB(...) \
    callWithGLCheck(glCompressedTexImage2DARB, __VA_ARGS__)
#define _glCompressedTexImage3D(...) \
    callWithGLCheck(glCompressedTexImage3D, __VA_ARGS__)
#define _glCompressedTexImage3DARB(...) \
    callWithGLCheck(glCompressedTexImage3DARB, __VA_ARGS__)
#define _glCompressedTexSubImage1D(...) \
    callWithGLCheck(glCompressedTexSubImage1D, __VA_ARGS__)
#define _glCompressedTexSubImage1DARB(...) \
    callWithGLCheck(glCompressedTexSubImage1DARB, __VA_ARGS__)
#define _glCompressedTexSubImage2D(...) \
    callWithGLCheck(glCompressedTexSubImage2D, __VA_ARGS__)
#define _glCompressedTexSubImage2DARB(...) \
    callWithGLCheck(glCompressedTexSubImage2DARB, __VA_ARGS__)
#define _glCompressedTexSubImage3D(...) \
    callWithGLCheck(glCompressedTexSubImage3D, __VA_ARGS__)
#define _glCompressedTexSubImage3DARB(...) \
    callWithGLCheck(glCompressedTexSubImage3DARB, __VA_ARGS__)
#define _glConvolutionFilter1D(...) \
    callWithGLCheck(glConvolutionFilter1D, __VA_ARGS__)
#define _glConvolutionFilter2D(...) \
    callWithGLCheck(glConvolutionFilter2D, __VA_ARGS__)
#define _glConvolutionParameterf(...) \
    callWithGLCheck(glConvolutionParameterf, __VA_ARGS__)
#define _glConvolutionParameterfv(...) \
    callWithGLCheck(glConvolutionParameterfv, __VA_ARGS__)
#define _glConvolutionParameteri(...) \
    callWithGLCheck(glConvolutionParameteri, __VA_ARGS__)
#define _glConvolutionParameteriv(...) \
    callWithGLCheck(glConvolutionParameteriv, __VA_ARGS__)
#define _glCopyColorSubTable(...) \
    callWithGLCheck(glCopyColorSubTable, __VA_ARGS__)
#define _glCopyColorTable(...) callWithGLCheck(glCopyColorTable, __VA_ARGS__)
#define _glCopyConvolutionFilter1D(...) \
    callWithGLCheck(glCopyConvolutionFilter1D, __VA_ARGS__)
#define _glCopyConvolutionFilter2D(...) \
    callWithGLCheck(glCopyConvolutionFilter2D, __VA_ARGS__)
#define _glCopyPixels(...) callWithGLCheck(glCopyPixels, __VA_ARGS__)
#define _glCopyTexImage1D(...) callWithGLCheck(glCopyTexImage1D, __VA_ARGS__)
#define _glCopyTexImage2D(...) callWithGLCheck(glCopyTexImage2D, __VA_ARGS__)
#define _glCopyTexSubImage1D(...) \
    callWithGLCheck(glCopyTexSubImage1D, __VA_ARGS__)
#define _glCopyTexSubImage2D(...) \
    callWithGLCheck(glCopyTexSubImage2D, __VA_ARGS__)
#define _glCopyTexSubImage3D(...) \
    callWithGLCheck(glCopyTexSubImage3D, __VA_ARGS__)
#define _glCreateProgram(...) callWithGLCheck(glCreateProgram, __VA_ARGS__)
#define _glCreateProgramObjectARB(...) \
    callWithGLCheck(glCreateProgramObjectARB, __VA_ARGS__)
#define _glCreateShader(...) callWithGLCheck(glCreateShader, __VA_ARGS__)
#define _glCreateShaderObjectARB(...) \
    callWithGLCheck(glCreateShaderObjectARB, __VA_ARGS__)
#define _glCullFace(...) callWithGLCheck(glCullFace, __VA_ARGS__)
#define _glDeleteBuffers(...) callWithGLCheck(glDeleteBuffers, __VA_ARGS__)
#define _glDeleteBuffersARB(...) \
    callWithGLCheck(glDeleteBuffersARB, __VA_ARGS__)
#define _glDeleteFencesAPPLE(...) \
    callWithGLCheck(glDeleteFencesAPPLE, __VA_ARGS__)
#define _glDeleteFramebuffers(...) \
    callWithGLCheck(glDeleteFramebuffers, __VA_ARGS__)
#define _glDeleteFramebuffersEXT(...) \
    callWithGLCheck(glDeleteFramebuffersEXT, __VA_ARGS__)
#define _glDeleteLists(...) callWithGLCheck(glDeleteLists, __VA_ARGS__)
#define _glDeleteObjectARB(...) callWithGLCheck(glDeleteObjectARB, __VA_ARGS__)
#define _glDeleteProgram(...) callWithGLCheck(glDeleteProgram, __VA_ARGS__)
#define _glDeleteProgramsARB(...) \
    callWithGLCheck(glDeleteProgramsARB, __VA_ARGS__)
#define _glDeleteQueries(...) callWithGLCheck(glDeleteQueries, __VA_ARGS__)
#define _glDeleteQueriesARB(...) \
    callWithGLCheck(glDeleteQueriesARB, __VA_ARGS__)
#define _glDeleteRenderbuffers(...) \
    callWithGLCheck(glDeleteRenderbuffers, __VA_ARGS__)
#define _glDeleteRenderbuffersEXT(...) \
    callWithGLCheck(glDeleteRenderbuffersEXT, __VA_ARGS__)
#define _glDeleteShader(...) callWithGLCheck(glDeleteShader, __VA_ARGS__)
#define _glDeleteSync(...) callWithGLCheck(glDeleteSync, __VA_ARGS__)
#define _glDeleteTextures(...) callWithGLCheck(glDeleteTextures, __VA_ARGS__)
#define _glDeleteVertexArraysAPPLE(...) \
    callWithGLCheck(glDeleteVertexArraysAPPLE, __VA_ARGS__)
#define _glDepthBoundsEXT(...) callWithGLCheck(glDepthBoundsEXT, __VA_ARGS__)
#define _glDepthFunc(...) callWithGLCheck(glDepthFunc, __VA_ARGS__)
#define _glDepthMask(...) callWithGLCheck(glDepthMask, __VA_ARGS__)
#define _glDepthRange(...) callWithGLCheck(glDepthRange, __VA_ARGS__)
#define _glDetachObjectARB(...) callWithGLCheck(glDetachObjectARB, __VA_ARGS__)
#define _glDetachShader(...) callWithGLCheck(glDetachShader, __VA_ARGS__)
#define _glDisable(...) callWithGLCheck(glDisable, __VA_ARGS__)
#define _glDisableClientState(...) \
    callWithGLCheck(glDisableClientState, __VA_ARGS__)
#define _glDisableIndexedEXT(...) \
    callWithGLCheck(glDisableIndexedEXT, __VA_ARGS__)
#define _glDisableVertexAttribAPPLE(...) \
    callWithGLCheck(glDisableVertexAttribAPPLE, __VA_ARGS__)
#define _glDisableVertexAttribArray(...) \
    callWithGLCheck(glDisableVertexAttribArray, __VA_ARGS__)
#define _glDisableVertexAttribArrayARB(...) \
    callWithGLCheck(glDisableVertexAttribArrayARB, __VA_ARGS__)
#define _glDisablei(...) callWithGLCheck(glDisablei, __VA_ARGS__)
#define _glDrawArrays(...) callWithGLCheck(glDrawArrays, __VA_ARGS__)
#define _glDrawArraysInstancedARB(...) \
    callWithGLCheck(glDrawArraysInstancedARB, __VA_ARGS__)
#define _glDrawBuffer(...) callWithGLCheck(glDrawBuffer, __VA_ARGS__)
#define _glDrawBuffers(...) callWithGLCheck(glDrawBuffers, __VA_ARGS__)
#define _glDrawBuffersARB(...) callWithGLCheck(glDrawBuffersARB, __VA_ARGS__)
#define _glDrawElementArrayAPPLE(...) \
    callWithGLCheck(glDrawElementArrayAPPLE, __VA_ARGS__)
#define _glDrawElements(...) callWithGLCheck(glDrawElements, __VA_ARGS__)
#define _glDrawElementsBaseVertex(...) \
    callWithGLCheck(glDrawElementsBaseVertex, __VA_ARGS__)
#define _glDrawElementsInstancedARB(...) \
    callWithGLCheck(glDrawElementsInstancedARB, __VA_ARGS__)
#define _glDrawElementsInstancedBaseVertex(...) \
    callWithGLCheck(glDrawElementsInstancedBaseVertex, __VA_ARGS__)
#define _glDrawPixels(...) callWithGLCheck(glDrawPixels, __VA_ARGS__)
#define _glDrawRangeElementArrayAPPLE(...) \
    callWithGLCheck(glDrawRangeElementArrayAPPLE, __VA_ARGS__)
#define _glDrawRangeElements(...) \
    callWithGLCheck(glDrawRangeElements, __VA_ARGS__)
#define _glDrawRangeElementsBaseVertex(...) \
    callWithGLCheck(glDrawRangeElementsBaseVertex, __VA_ARGS__)
#define _glDrawRangeElementsEXT(...) \
    callWithGLCheck(glDrawRangeElementsEXT, __VA_ARGS__)
#define _glEdgeFlag(...) callWithGLCheck(glEdgeFlag, __VA_ARGS__)
#define _glEdgeFlagPointer(...) callWithGLCheck(glEdgeFlagPointer, __VA_ARGS__)
#define _glEdgeFlagv(...) callWithGLCheck(glEdgeFlagv, __VA_ARGS__)
#define _glElementPointerAPPLE(...) \
    callWithGLCheck(glElementPointerAPPLE, __VA_ARGS__)
#define _glEnable(...) callWithGLCheck(glEnable, __VA_ARGS__)
#define _glEnableClientState(...) \
    callWithGLCheck(glEnableClientState, __VA_ARGS__)
#define _glEnableIndexedEXT(...) \
    callWithGLCheck(glEnableIndexedEXT, __VA_ARGS__)
#define _glEnableVertexAttribAPPLE(...) \
    callWithGLCheck(glEnableVertexAttribAPPLE, __VA_ARGS__)
#define _glEnableVertexAttribArray(...) \
    callWithGLCheck(glEnableVertexAttribArray, __VA_ARGS__)
#define _glEnableVertexAttribArrayARB(...) \
    callWithGLCheck(glEnableVertexAttribArrayARB, __VA_ARGS__)
#define _glEnablei(...) callWithGLCheck(glEnablei, __VA_ARGS__)
#define _glEnd(...) callWithGLCheck(glEnd, __VA_ARGS__)
#define _glEndConditionalRender(...) \
    callWithGLCheck(glEndConditionalRender, __VA_ARGS__)
#define _glEndConditionalRenderNV(...) \
    callWithGLCheck(glEndConditionalRenderNV, __VA_ARGS__)
#define _glEndList(...) callWithGLCheck(glEndList, __VA_ARGS__)
#define _glEndQuery(...) callWithGLCheck(glEndQuery, __VA_ARGS__)
#define _glEndQueryARB(...) callWithGLCheck(glEndQueryARB, __VA_ARGS__)
#define _glEndTransformFeedback(...) \
    callWithGLCheck(glEndTransformFeedback, __VA_ARGS__)
#define _glEndTransformFeedbackEXT(...) \
    callWithGLCheck(glEndTransformFeedbackEXT, __VA_ARGS__)
#define _glEvalCoord1d(...) callWithGLCheck(glEvalCoord1d, __VA_ARGS__)
#define _glEvalCoord1dv(...) callWithGLCheck(glEvalCoord1dv, __VA_ARGS__)
#define _glEvalCoord1f(...) callWithGLCheck(glEvalCoord1f, __VA_ARGS__)
#define _glEvalCoord1fv(...) callWithGLCheck(glEvalCoord1fv, __VA_ARGS__)
#define _glEvalCoord2d(...) callWithGLCheck(glEvalCoord2d, __VA_ARGS__)
#define _glEvalCoord2dv(...) callWithGLCheck(glEvalCoord2dv, __VA_ARGS__)
#define _glEvalCoord2f(...) callWithGLCheck(glEvalCoord2f, __VA_ARGS__)
#define _glEvalCoord2fv(...) callWithGLCheck(glEvalCoord2fv, __VA_ARGS__)
#define _glEvalMesh1(...) callWithGLCheck(glEvalMesh1, __VA_ARGS__)
#define _glEvalMesh2(...) callWithGLCheck(glEvalMesh2, __VA_ARGS__)
#define _glEvalPoint1(...) callWithGLCheck(glEvalPoint1, __VA_ARGS__)
#define _glEvalPoint2(...) callWithGLCheck(glEvalPoint2, __VA_ARGS__)
#define _glFeedbackBuffer(...) callWithGLCheck(glFeedbackBuffer, __VA_ARGS__)
#define _glFenceSync(...) callWithGLCheck(glFenceSync, __VA_ARGS__)
#define _glFinish(...) callWithGLCheck(glFinish, __VA_ARGS__)
#define _glFinishFenceAPPLE(...) \
    callWithGLCheck(glFinishFenceAPPLE, __VA_ARGS__)
#define _glFinishObjectAPPLE(...) \
    callWithGLCheck(glFinishObjectAPPLE, __VA_ARGS__)
#define _glFinishRenderAPPLE(...) \
    callWithGLCheck(glFinishRenderAPPLE, __VA_ARGS__)
#define _glFlush(...) callWithGLCheck(glFlush, __VA_ARGS__)
#define _glFlushMappedBufferRangeAPPLE(...) \
    callWithGLCheck(glFlushMappedBufferRangeAPPLE, __VA_ARGS__)
#define _glFlushRenderAPPLE(...) \
    callWithGLCheck(glFlushRenderAPPLE, __VA_ARGS__)
#define _glFlushVertexArrayRangeAPPLE(...) \
    callWithGLCheck(glFlushVertexArrayRangeAPPLE, __VA_ARGS__)
#define _glFogCoordPointer(...) callWithGLCheck(glFogCoordPointer, __VA_ARGS__)
#define _glFogCoordPointerEXT(...) \
    callWithGLCheck(glFogCoordPointerEXT, __VA_ARGS__)
#define _glFogCoordd(...) callWithGLCheck(glFogCoordd, __VA_ARGS__)
#define _glFogCoorddEXT(...) callWithGLCheck(glFogCoorddEXT, __VA_ARGS__)
#define _glFogCoorddv(...) callWithGLCheck(glFogCoorddv, __VA_ARGS__)
#define _glFogCoorddvEXT(...) callWithGLCheck(glFogCoorddvEXT, __VA_ARGS__)
#define _glFogCoordf(...) callWithGLCheck(glFogCoordf, __VA_ARGS__)
#define _glFogCoordfEXT(...) callWithGLCheck(glFogCoordfEXT, __VA_ARGS__)
#define _glFogCoordfv(...) callWithGLCheck(glFogCoordfv, __VA_ARGS__)
#define _glFogCoordfvEXT(...) callWithGLCheck(glFogCoordfvEXT, __VA_ARGS__)
#define _glFogf(...) callWithGLCheck(glFogf, __VA_ARGS__)
#define _glFogfv(...) callWithGLCheck(glFogfv, __VA_ARGS__)
#define _glFogi(...) callWithGLCheck(glFogi, __VA_ARGS__)
#define _glFogiv(...) callWithGLCheck(glFogiv, __VA_ARGS__)
#define _glFramebufferRenderbuffer(...) \
    callWithGLCheck(glFramebufferRenderbuffer, __VA_ARGS__)
#define _glFramebufferRenderbufferEXT(...) \
    callWithGLCheck(glFramebufferRenderbufferEXT, __VA_ARGS__)
#define _glFramebufferTexture1D(...) \
    callWithGLCheck(glFramebufferTexture1D, __VA_ARGS__)
#define _glFramebufferTexture1DEXT(...) \
    callWithGLCheck(glFramebufferTexture1DEXT, __VA_ARGS__)
#define _glFramebufferTexture2D(...) \
    callWithGLCheck(glFramebufferTexture2D, __VA_ARGS__)
#define _glFramebufferTexture2DEXT(...) \
    callWithGLCheck(glFramebufferTexture2DEXT, __VA_ARGS__)
#define _glFramebufferTexture3D(...) \
    callWithGLCheck(glFramebufferTexture3D, __VA_ARGS__)
#define _glFramebufferTexture3DEXT(...) \
    callWithGLCheck(glFramebufferTexture3DEXT, __VA_ARGS__)
#define _glFramebufferTextureEXT(...) \
    callWithGLCheck(glFramebufferTextureEXT, __VA_ARGS__)
#define _glFramebufferTextureFaceEXT(...) \
    callWithGLCheck(glFramebufferTextureFaceEXT, __VA_ARGS__)
#define _glFramebufferTextureLayer(...) \
    callWithGLCheck(glFramebufferTextureLayer, __VA_ARGS__)
#define _glFramebufferTextureLayerEXT(...) \
    callWithGLCheck(glFramebufferTextureLayerEXT, __VA_ARGS__)
#define _glFrontFace(...) callWithGLCheck(glFrontFace, __VA_ARGS__)
#define _glFrustum(...) callWithGLCheck(glFrustum, __VA_ARGS__)
#define _glGenBuffers(...) callWithGLCheck(glGenBuffers, __VA_ARGS__)
#define _glGenBuffersARB(...) callWithGLCheck(glGenBuffersARB, __VA_ARGS__)
#define _glGenFencesAPPLE(...) callWithGLCheck(glGenFencesAPPLE, __VA_ARGS__)
#define _glGenFramebuffers(...) callWithGLCheck(glGenFramebuffers, __VA_ARGS__)
#define _glGenFramebuffersEXT(...) \
    callWithGLCheck(glGenFramebuffersEXT, __VA_ARGS__)
#define _glGenLists(...) callWithGLCheck(glGenLists, __VA_ARGS__)
#define _glGenProgramsARB(...) callWithGLCheck(glGenProgramsARB, __VA_ARGS__)
#define _glGenQueries(...) callWithGLCheck(glGenQueries, __VA_ARGS__)
#define _glGenQueriesARB(...) callWithGLCheck(glGenQueriesARB, __VA_ARGS__)
#define _glGenRenderbuffers(...) \
    callWithGLCheck(glGenRenderbuffers, __VA_ARGS__)
#define _glGenRenderbuffersEXT(...) \
    callWithGLCheck(glGenRenderbuffersEXT, __VA_ARGS__)
#define _glGenTextures(...) callWithGLCheck(glGenTextures, __VA_ARGS__)
#define _glGenVertexArraysAPPLE(...) \
    callWithGLCheck(glGenVertexArraysAPPLE, __VA_ARGS__)
#define _glGenerateMipmap(...) callWithGLCheck(glGenerateMipmap, __VA_ARGS__)
#define _glGenerateMipmapEXT(...) \
    callWithGLCheck(glGenerateMipmapEXT, __VA_ARGS__)
#define _glGetActiveAttrib(...) callWithGLCheck(glGetActiveAttrib, __VA_ARGS__)
#define _glGetActiveAttribARB(...) \
    callWithGLCheck(glGetActiveAttribARB, __VA_ARGS__)
#define _glGetActiveUniform(...) \
    callWithGLCheck(glGetActiveUniform, __VA_ARGS__)
#define _glGetActiveUniformARB(...) \
    callWithGLCheck(glGetActiveUniformARB, __VA_ARGS__)
#define _glGetAttachedObjectsARB(...) \
    callWithGLCheck(glGetAttachedObjectsARB, __VA_ARGS__)
#define _glGetAttachedShaders(...) \
    callWithGLCheck(glGetAttachedShaders, __VA_ARGS__)
#define _glGetAttribLocation(...) \
    callWithGLCheck(glGetAttribLocation, __VA_ARGS__)
#define _glGetAttribLocationARB(...) \
    callWithGLCheck(glGetAttribLocationARB, __VA_ARGS__)
#define _glGetBooleanIndexedvEXT(...) \
    callWithGLCheck(glGetBooleanIndexedvEXT, __VA_ARGS__)
#define _glGetBooleani_v(...) callWithGLCheck(glGetBooleani_v, __VA_ARGS__)
#define _glGetBooleanv(...) callWithGLCheck(glGetBooleanv, __VA_ARGS__)
#define _glGetBufferParameteriv(...) \
    callWithGLCheck(glGetBufferParameteriv, __VA_ARGS__)
#define _glGetBufferParameterivARB(...) \
    callWithGLCheck(glGetBufferParameterivARB, __VA_ARGS__)
#define _glGetBufferPointerv(...) \
    callWithGLCheck(glGetBufferPointerv, __VA_ARGS__)
#define _glGetBufferPointervARB(...) \
    callWithGLCheck(glGetBufferPointervARB, __VA_ARGS__)
#define _glGetBufferSubData(...) \
    callWithGLCheck(glGetBufferSubData, __VA_ARGS__)
#define _glGetBufferSubDataARB(...) \
    callWithGLCheck(glGetBufferSubDataARB, __VA_ARGS__)
#define _glGetClipPlane(...) callWithGLCheck(glGetClipPlane, __VA_ARGS__)
#define _glGetColorTable(...) callWithGLCheck(glGetColorTable, __VA_ARGS__)
#define _glGetColorTableEXT(...) \
    callWithGLCheck(glGetColorTableEXT, __VA_ARGS__)
#define _glGetColorTableParameterfv(...) \
    callWithGLCheck(glGetColorTableParameterfv, __VA_ARGS__)
#define _glGetColorTableParameterfvEXT(...) \
    callWithGLCheck(glGetColorTableParameterfvEXT, __VA_ARGS__)
#define _glGetColorTableParameteriv(...) \
    callWithGLCheck(glGetColorTableParameteriv, __VA_ARGS__)
#define _glGetColorTableParameterivEXT(...) \
    callWithGLCheck(glGetColorTableParameterivEXT, __VA_ARGS__)
#define _glGetCompressedTexImage(...) \
    callWithGLCheck(glGetCompressedTexImage, __VA_ARGS__)
#define _glGetCompressedTexImageARB(...) \
    callWithGLCheck(glGetCompressedTexImageARB, __VA_ARGS__)
#define _glGetConvolutionFilter(...) \
    callWithGLCheck(glGetConvolutionFilter, __VA_ARGS__)
#define _glGetConvolutionParameterfv(...) \
    callWithGLCheck(glGetConvolutionParameterfv, __VA_ARGS__)
#define _glGetConvolutionParameteriv(...) \
    callWithGLCheck(glGetConvolutionParameteriv, __VA_ARGS__)
#define _glGetDoublev(...) callWithGLCheck(glGetDoublev, __VA_ARGS__)
#define _glGetError(...) callWithGLCheck(glGetError, __VA_ARGS__)
#define _glGetFloatv(...) callWithGLCheck(glGetFloatv, __VA_ARGS__)
#define _glGetFragDataLocation(...) \
    callWithGLCheck(glGetFragDataLocation, __VA_ARGS__)
#define _glGetFragDataLocationEXT(...) \
    callWithGLCheck(glGetFragDataLocationEXT, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameteriv(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameteriv, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameterivEXT(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameterivEXT, __VA_ARGS__)
#define _glGetHandleARB(...) callWithGLCheck(glGetHandleARB, __VA_ARGS__)
#define _glGetHistogram(...) callWithGLCheck(glGetHistogram, __VA_ARGS__)
#define _glGetHistogramParameterfv(...) \
    callWithGLCheck(glGetHistogramParameterfv, __VA_ARGS__)
#define _glGetHistogramParameteriv(...) \
    callWithGLCheck(glGetHistogramParameteriv, __VA_ARGS__)
#define _glGetInfoLogARB(...) callWithGLCheck(glGetInfoLogARB, __VA_ARGS__)
#define _glGetInteger64v(...) callWithGLCheck(glGetInteger64v, __VA_ARGS__)
#define _glGetIntegerIndexedvEXT(...) \
    callWithGLCheck(glGetIntegerIndexedvEXT, __VA_ARGS__)
#define _glGetIntegeri_v(...) callWithGLCheck(glGetIntegeri_v, __VA_ARGS__)
#define _glGetIntegerv(...) callWithGLCheck(glGetIntegerv, __VA_ARGS__)
#define _glGetLightfv(...) callWithGLCheck(glGetLightfv, __VA_ARGS__)
#define _glGetLightiv(...) callWithGLCheck(glGetLightiv, __VA_ARGS__)
#define _glGetMapdv(...) callWithGLCheck(glGetMapdv, __VA_ARGS__)
#define _glGetMapfv(...) callWithGLCheck(glGetMapfv, __VA_ARGS__)
#define _glGetMapiv(...) callWithGLCheck(glGetMapiv, __VA_ARGS__)
#define _glGetMaterialfv(...) callWithGLCheck(glGetMaterialfv, __VA_ARGS__)
#define _glGetMaterialiv(...) callWithGLCheck(glGetMaterialiv, __VA_ARGS__)
#define _glGetMinmax(...) callWithGLCheck(glGetMinmax, __VA_ARGS__)
#define _glGetMinmaxParameterfv(...) \
    callWithGLCheck(glGetMinmaxParameterfv, __VA_ARGS__)
#define _glGetMinmaxParameteriv(...) \
    callWithGLCheck(glGetMinmaxParameteriv, __VA_ARGS__)
#define _glGetObjectLabelEXT(...) \
    callWithGLCheck(glGetObjectLabelEXT, __VA_ARGS__)
#define _glGetObjectParameterfvARB(...) \
    callWithGLCheck(glGetObjectParameterfvARB, __VA_ARGS__)
#define _glGetObjectParameterivAPPLE(...) \
    callWithGLCheck(glGetObjectParameterivAPPLE, __VA_ARGS__)
#define _glGetObjectParameterivARB(...) \
    callWithGLCheck(glGetObjectParameterivARB, __VA_ARGS__)
#define _glGetPixelMapfv(...) callWithGLCheck(glGetPixelMapfv, __VA_ARGS__)
#define _glGetPixelMapuiv(...) callWithGLCheck(glGetPixelMapuiv, __VA_ARGS__)
#define _glGetPixelMapusv(...) callWithGLCheck(glGetPixelMapusv, __VA_ARGS__)
#define _glGetPointerv(...) callWithGLCheck(glGetPointerv, __VA_ARGS__)
#define _glGetPolygonStipple(...) \
    callWithGLCheck(glGetPolygonStipple, __VA_ARGS__)
#define _glGetProgramEnvParameterdvARB(...) \
    callWithGLCheck(glGetProgramEnvParameterdvARB, __VA_ARGS__)
#define _glGetProgramEnvParameterfvARB(...) \
    callWithGLCheck(glGetProgramEnvParameterfvARB, __VA_ARGS__)
#define _glGetProgramInfoLog(...) \
    callWithGLCheck(glGetProgramInfoLog, __VA_ARGS__)
#define _glGetProgramLocalParameterdvARB(...) \
    callWithGLCheck(glGetProgramLocalParameterdvARB, __VA_ARGS__)
#define _glGetProgramLocalParameterfvARB(...) \
    callWithGLCheck(glGetProgramLocalParameterfvARB, __VA_ARGS__)
#define _glGetProgramStringARB(...) \
    callWithGLCheck(glGetProgramStringARB, __VA_ARGS__)
#define _glGetProgramiv(...) callWithGLCheck(glGetProgramiv, __VA_ARGS__)
#define _glGetProgramivARB(...) callWithGLCheck(glGetProgramivARB, __VA_ARGS__)
#define _glGetQueryObjecti64vEXT(...) \
    callWithGLCheck(glGetQueryObjecti64vEXT, __VA_ARGS__)
#define _glGetQueryObjectiv(...) \
    callWithGLCheck(glGetQueryObjectiv, __VA_ARGS__)
#define _glGetQueryObjectivARB(...) \
    callWithGLCheck(glGetQueryObjectivARB, __VA_ARGS__)
#define _glGetQueryObjectui64vEXT(...) \
    callWithGLCheck(glGetQueryObjectui64vEXT, __VA_ARGS__)
#define _glGetQueryObjectuiv(...) \
    callWithGLCheck(glGetQueryObjectuiv, __VA_ARGS__)
#define _glGetQueryObjectuivARB(...) \
    callWithGLCheck(glGetQueryObjectuivARB, __VA_ARGS__)
#define _glGetQueryiv(...) callWithGLCheck(glGetQueryiv, __VA_ARGS__)
#define _glGetQueryivARB(...) callWithGLCheck(glGetQueryivARB, __VA_ARGS__)
#define _glGetRenderbufferParameteriv(...) \
    callWithGLCheck(glGetRenderbufferParameteriv, __VA_ARGS__)
#define _glGetRenderbufferParameterivEXT(...) \
    callWithGLCheck(glGetRenderbufferParameterivEXT, __VA_ARGS__)
#define _glGetSeparableFilter(...) \
    callWithGLCheck(glGetSeparableFilter, __VA_ARGS__)
#define _glGetShaderInfoLog(...) \
    callWithGLCheck(glGetShaderInfoLog, __VA_ARGS__)
#define _glGetShaderSource(...) callWithGLCheck(glGetShaderSource, __VA_ARGS__)
#define _glGetShaderSourceARB(...) \
    callWithGLCheck(glGetShaderSourceARB, __VA_ARGS__)
#define _glGetShaderiv(...) callWithGLCheck(glGetShaderiv, __VA_ARGS__)
#define _glGetString(...) callWithGLCheck(glGetString, __VA_ARGS__)
#define _glGetStringi(...) callWithGLCheck(glGetStringi, __VA_ARGS__)
#define _glGetSynciv(...) callWithGLCheck(glGetSynciv, __VA_ARGS__)
#define _glGetTexEnvfv(...) callWithGLCheck(glGetTexEnvfv, __VA_ARGS__)
#define _glGetTexEnviv(...) callWithGLCheck(glGetTexEnviv, __VA_ARGS__)
#define _glGetTexGendv(...) callWithGLCheck(glGetTexGendv, __VA_ARGS__)
#define _glGetTexGenfv(...) callWithGLCheck(glGetTexGenfv, __VA_ARGS__)
#define _glGetTexGeniv(...) callWithGLCheck(glGetTexGeniv, __VA_ARGS__)
#define _glGetTexImage(...) callWithGLCheck(glGetTexImage, __VA_ARGS__)
#define _glGetTexLevelParameterfv(...) \
    callWithGLCheck(glGetTexLevelParameterfv, __VA_ARGS__)
#define _glGetTexLevelParameteriv(...) \
    callWithGLCheck(glGetTexLevelParameteriv, __VA_ARGS__)
#define _glGetTexParameterIiv(...) \
    callWithGLCheck(glGetTexParameterIiv, __VA_ARGS__)
#define _glGetTexParameterIivEXT(...) \
    callWithGLCheck(glGetTexParameterIivEXT, __VA_ARGS__)
#define _glGetTexParameterIuiv(...) \
    callWithGLCheck(glGetTexParameterIuiv, __VA_ARGS__)
#define _glGetTexParameterIuivEXT(...) \
    callWithGLCheck(glGetTexParameterIuivEXT, __VA_ARGS__)
#define _glGetTexParameterPointervAPPLE(...) \
    callWithGLCheck(glGetTexParameterPointervAPPLE, __VA_ARGS__)
#define _glGetTexParameterfv(...) \
    callWithGLCheck(glGetTexParameterfv, __VA_ARGS__)
#define _glGetTexParameteriv(...) \
    callWithGLCheck(glGetTexParameteriv, __VA_ARGS__)
#define _glGetTransformFeedbackVarying(...) \
    callWithGLCheck(glGetTransformFeedbackVarying, __VA_ARGS__)
#define _glGetTransformFeedbackVaryingEXT(...) \
    callWithGLCheck(glGetTransformFeedbackVaryingEXT, __VA_ARGS__)
#define _glGetUniformBufferSizeEXT(...) \
    callWithGLCheck(glGetUniformBufferSizeEXT, __VA_ARGS__)
#define _glGetUniformLocation(...) \
    callWithGLCheck(glGetUniformLocation, __VA_ARGS__)
#define _glGetUniformLocationARB(...) \
    callWithGLCheck(glGetUniformLocationARB, __VA_ARGS__)
#define _glGetUniformOffsetEXT(...) \
    callWithGLCheck(glGetUniformOffsetEXT, __VA_ARGS__)
#define _glGetUniformfv(...) callWithGLCheck(glGetUniformfv, __VA_ARGS__)
#define _glGetUniformfvARB(...) callWithGLCheck(glGetUniformfvARB, __VA_ARGS__)
#define _glGetUniformiv(...) callWithGLCheck(glGetUniformiv, __VA_ARGS__)
#define _glGetUniformivARB(...) callWithGLCheck(glGetUniformivARB, __VA_ARGS__)
#define _glGetUniformuiv(...) callWithGLCheck(glGetUniformuiv, __VA_ARGS__)
#define _glGetUniformuivEXT(...) \
    callWithGLCheck(glGetUniformuivEXT, __VA_ARGS__)
#define _glGetVertexAttribIiv(...) \
    callWithGLCheck(glGetVertexAttribIiv, __VA_ARGS__)
#define _glGetVertexAttribIivEXT(...) \
    callWithGLCheck(glGetVertexAttribIivEXT, __VA_ARGS__)
#define _glGetVertexAttribIuiv(...) \
    callWithGLCheck(glGetVertexAttribIuiv, __VA_ARGS__)
#define _glGetVertexAttribIuivEXT(...) \
    callWithGLCheck(glGetVertexAttribIuivEXT, __VA_ARGS__)
#define _glGetVertexAttribPointerv(...) \
    callWithGLCheck(glGetVertexAttribPointerv, __VA_ARGS__)
#define _glGetVertexAttribPointervARB(...) \
    callWithGLCheck(glGetVertexAttribPointervARB, __VA_ARGS__)
#define _glGetVertexAttribdv(...) \
    callWithGLCheck(glGetVertexAttribdv, __VA_ARGS__)
#define _glGetVertexAttribdvARB(...) \
    callWithGLCheck(glGetVertexAttribdvARB, __VA_ARGS__)
#define _glGetVertexAttribfv(...) \
    callWithGLCheck(glGetVertexAttribfv, __VA_ARGS__)
#define _glGetVertexAttribfvARB(...) \
    callWithGLCheck(glGetVertexAttribfvARB, __VA_ARGS__)
#define _glGetVertexAttribiv(...) \
    callWithGLCheck(glGetVertexAttribiv, __VA_ARGS__)
#define _glGetVertexAttribivARB(...) \
    callWithGLCheck(glGetVertexAttribivARB, __VA_ARGS__)
#define _glHint(...) callWithGLCheck(glHint, __VA_ARGS__)
#define _glHistogram(...) callWithGLCheck(glHistogram, __VA_ARGS__)
#define _glIndexMask(...) callWithGLCheck(glIndexMask, __VA_ARGS__)
#define _glIndexPointer(...) callWithGLCheck(glIndexPointer, __VA_ARGS__)
#define _glIndexd(...) callWithGLCheck(glIndexd, __VA_ARGS__)
#define _glIndexdv(...) callWithGLCheck(glIndexdv, __VA_ARGS__)
#define _glIndexf(...) callWithGLCheck(glIndexf, __VA_ARGS__)
#define _glIndexfv(...) callWithGLCheck(glIndexfv, __VA_ARGS__)
#define _glIndexi(...) callWithGLCheck(glIndexi, __VA_ARGS__)
#define _glIndexiv(...) callWithGLCheck(glIndexiv, __VA_ARGS__)
#define _glIndexs(...) callWithGLCheck(glIndexs, __VA_ARGS__)
#define _glIndexsv(...) callWithGLCheck(glIndexsv, __VA_ARGS__)
#define _glIndexub(...) callWithGLCheck(glIndexub, __VA_ARGS__)
#define _glIndexubv(...) callWithGLCheck(glIndexubv, __VA_ARGS__)
#define _glInitNames(...) callWithGLCheck(glInitNames, __VA_ARGS__)
#define _glInsertEventMarkerEXT(...) \
    callWithGLCheck(glInsertEventMarkerEXT, __VA_ARGS__)
#define _glInterleavedArrays(...) \
    callWithGLCheck(glInterleavedArrays, __VA_ARGS__)
#define _glIsBuffer(...) callWithGLCheck(glIsBuffer, __VA_ARGS__)
#define _glIsBufferARB(...) callWithGLCheck(glIsBufferARB, __VA_ARGS__)
#define _glIsEnabled(...) callWithGLCheck(glIsEnabled, __VA_ARGS__)
#define _glIsEnabledIndexedEXT(...) \
    callWithGLCheck(glIsEnabledIndexedEXT, __VA_ARGS__)
#define _glIsEnabledi(...) callWithGLCheck(glIsEnabledi, __VA_ARGS__)
#define _glIsFenceAPPLE(...) callWithGLCheck(glIsFenceAPPLE, __VA_ARGS__)
#define _glIsFramebuffer(...) callWithGLCheck(glIsFramebuffer, __VA_ARGS__)
#define _glIsFramebufferEXT(...) \
    callWithGLCheck(glIsFramebufferEXT, __VA_ARGS__)
#define _glIsList(...) callWithGLCheck(glIsList, __VA_ARGS__)
#define _glIsProgram(...) callWithGLCheck(glIsProgram, __VA_ARGS__)
#define _glIsProgramARB(...) callWithGLCheck(glIsProgramARB, __VA_ARGS__)
#define _glIsQuery(...) callWithGLCheck(glIsQuery, __VA_ARGS__)
#define _glIsQueryARB(...) callWithGLCheck(glIsQueryARB, __VA_ARGS__)
#define _glIsRenderbuffer(...) callWithGLCheck(glIsRenderbuffer, __VA_ARGS__)
#define _glIsRenderbufferEXT(...) \
    callWithGLCheck(glIsRenderbufferEXT, __VA_ARGS__)
#define _glIsShader(...) callWithGLCheck(glIsShader, __VA_ARGS__)
#define _glIsSync(...) callWithGLCheck(glIsSync, __VA_ARGS__)
#define _glIsTexture(...) callWithGLCheck(glIsTexture, __VA_ARGS__)
#define _glIsVertexArrayAPPLE(...) \
    callWithGLCheck(glIsVertexArrayAPPLE, __VA_ARGS__)
#define _glIsVertexAttribEnabledAPPLE(...) \
    callWithGLCheck(glIsVertexAttribEnabledAPPLE, __VA_ARGS__)
#define _glLabelObjectEXT(...) callWithGLCheck(glLabelObjectEXT, __VA_ARGS__)
#define _glLightModelf(...) callWithGLCheck(glLightModelf, __VA_ARGS__)
#define _glLightModelfv(...) callWithGLCheck(glLightModelfv, __VA_ARGS__)
#define _glLightModeli(...) callWithGLCheck(glLightModeli, __VA_ARGS__)
#define _glLightModeliv(...) callWithGLCheck(glLightModeliv, __VA_ARGS__)
#define _glLightf(...) callWithGLCheck(glLightf, __VA_ARGS__)
#define _glLightfv(...) callWithGLCheck(glLightfv, __VA_ARGS__)
#define _glLighti(...) callWithGLCheck(glLighti, __VA_ARGS__)
#define _glLightiv(...) callWithGLCheck(glLightiv, __VA_ARGS__)
#define _glLineStipple(...) callWithGLCheck(glLineStipple, __VA_ARGS__)
#define _glLineWidth(...) callWithGLCheck(glLineWidth, __VA_ARGS__)
#define _glLinkProgram(...) callWithGLCheck(glLinkProgram, __VA_ARGS__)
#define _glLinkProgramARB(...) callWithGLCheck(glLinkProgramARB, __VA_ARGS__)
#define _glListBase(...) callWithGLCheck(glListBase, __VA_ARGS__)
#define _glLoadIdentity(...) callWithGLCheck(glLoadIdentity, __VA_ARGS__)
#define _glLoadMatrixd(...) callWithGLCheck(glLoadMatrixd, __VA_ARGS__)
#define _glLoadMatrixf(...) callWithGLCheck(glLoadMatrixf, __VA_ARGS__)
#define _glLoadName(...) callWithGLCheck(glLoadName, __VA_ARGS__)
#define _glLoadTransposeMatrixd(...) \
    callWithGLCheck(glLoadTransposeMatrixd, __VA_ARGS__)
#define _glLoadTransposeMatrixdARB(...) \
    callWithGLCheck(glLoadTransposeMatrixdARB, __VA_ARGS__)
#define _glLoadTransposeMatrixf(...) \
    callWithGLCheck(glLoadTransposeMatrixf, __VA_ARGS__)
#define _glLoadTransposeMatrixfARB(...) \
    callWithGLCheck(glLoadTransposeMatrixfARB, __VA_ARGS__)
#define _glLogicOp(...) callWithGLCheck(glLogicOp, __VA_ARGS__)
#define _glMap1d(...) callWithGLCheck(glMap1d, __VA_ARGS__)
#define _glMap1f(...) callWithGLCheck(glMap1f, __VA_ARGS__)
#define _glMap2d(...) callWithGLCheck(glMap2d, __VA_ARGS__)
#define _glMap2f(...) callWithGLCheck(glMap2f, __VA_ARGS__)
#define _glMapBuffer(...) callWithGLCheck(glMapBuffer, __VA_ARGS__)
#define _glMapBufferARB(...) callWithGLCheck(glMapBufferARB, __VA_ARGS__)
#define _glMapGrid1d(...) callWithGLCheck(glMapGrid1d, __VA_ARGS__)
#define _glMapGrid1f(...) callWithGLCheck(glMapGrid1f, __VA_ARGS__)
#define _glMapGrid2d(...) callWithGLCheck(glMapGrid2d, __VA_ARGS__)
#define _glMapGrid2f(...) callWithGLCheck(glMapGrid2f, __VA_ARGS__)
#define _glMapVertexAttrib1dAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib1dAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib1fAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib1fAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib2dAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib2dAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib2fAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib2fAPPLE, __VA_ARGS__)
#define _glMaterialf(...) callWithGLCheck(glMaterialf, __VA_ARGS__)
#define _glMaterialfv(...) callWithGLCheck(glMaterialfv, __VA_ARGS__)
#define _glMateriali(...) callWithGLCheck(glMateriali, __VA_ARGS__)
#define _glMaterialiv(...) callWithGLCheck(glMaterialiv, __VA_ARGS__)
#define _glMatrixMode(...) callWithGLCheck(glMatrixMode, __VA_ARGS__)
#define _glMinmax(...) callWithGLCheck(glMinmax, __VA_ARGS__)
#define _glMultMatrixd(...) callWithGLCheck(glMultMatrixd, __VA_ARGS__)
#define _glMultMatrixf(...) callWithGLCheck(glMultMatrixf, __VA_ARGS__)
#define _glMultTransposeMatrixd(...) \
    callWithGLCheck(glMultTransposeMatrixd, __VA_ARGS__)
#define _glMultTransposeMatrixdARB(...) \
    callWithGLCheck(glMultTransposeMatrixdARB, __VA_ARGS__)
#define _glMultTransposeMatrixf(...) \
    callWithGLCheck(glMultTransposeMatrixf, __VA_ARGS__)
#define _glMultTransposeMatrixfARB(...) \
    callWithGLCheck(glMultTransposeMatrixfARB, __VA_ARGS__)
#define _glMultiDrawArrays(...) callWithGLCheck(glMultiDrawArrays, __VA_ARGS__)
#define _glMultiDrawArraysEXT(...) \
    callWithGLCheck(glMultiDrawArraysEXT, __VA_ARGS__)
#define _glMultiDrawElementArrayAPPLE(...) \
    callWithGLCheck(glMultiDrawElementArrayAPPLE, __VA_ARGS__)
#define _glMultiDrawElements(...) \
    callWithGLCheck(glMultiDrawElements, __VA_ARGS__)
#define _glMultiDrawElementsBaseVertex(...) \
    callWithGLCheck(glMultiDrawElementsBaseVertex, __VA_ARGS__)
#define _glMultiDrawElementsEXT(...) \
    callWithGLCheck(glMultiDrawElementsEXT, __VA_ARGS__)
#define _glMultiDrawRangeElementArrayAPPLE(...) \
    callWithGLCheck(glMultiDrawRangeElementArrayAPPLE, __VA_ARGS__)
#define _glMultiTexCoord1d(...) callWithGLCheck(glMultiTexCoord1d, __VA_ARGS__)
#define _glMultiTexCoord1dARB(...) \
    callWithGLCheck(glMultiTexCoord1dARB, __VA_ARGS__)
#define _glMultiTexCoord1dv(...) \
    callWithGLCheck(glMultiTexCoord1dv, __VA_ARGS__)
#define _glMultiTexCoord1dvARB(...) \
    callWithGLCheck(glMultiTexCoord1dvARB, __VA_ARGS__)
#define _glMultiTexCoord1f(...) callWithGLCheck(glMultiTexCoord1f, __VA_ARGS__)
#define _glMultiTexCoord1fARB(...) \
    callWithGLCheck(glMultiTexCoord1fARB, __VA_ARGS__)
#define _glMultiTexCoord1fv(...) \
    callWithGLCheck(glMultiTexCoord1fv, __VA_ARGS__)
#define _glMultiTexCoord1fvARB(...) \
    callWithGLCheck(glMultiTexCoord1fvARB, __VA_ARGS__)
#define _glMultiTexCoord1i(...) callWithGLCheck(glMultiTexCoord1i, __VA_ARGS__)
#define _glMultiTexCoord1iARB(...) \
    callWithGLCheck(glMultiTexCoord1iARB, __VA_ARGS__)
#define _glMultiTexCoord1iv(...) \
    callWithGLCheck(glMultiTexCoord1iv, __VA_ARGS__)
#define _glMultiTexCoord1ivARB(...) \
    callWithGLCheck(glMultiTexCoord1ivARB, __VA_ARGS__)
#define _glMultiTexCoord1s(...) callWithGLCheck(glMultiTexCoord1s, __VA_ARGS__)
#define _glMultiTexCoord1sARB(...) \
    callWithGLCheck(glMultiTexCoord1sARB, __VA_ARGS__)
#define _glMultiTexCoord1sv(...) \
    callWithGLCheck(glMultiTexCoord1sv, __VA_ARGS__)
#define _glMultiTexCoord1svARB(...) \
    callWithGLCheck(glMultiTexCoord1svARB, __VA_ARGS__)
#define _glMultiTexCoord2d(...) callWithGLCheck(glMultiTexCoord2d, __VA_ARGS__)
#define _glMultiTexCoord2dARB(...) \
    callWithGLCheck(glMultiTexCoord2dARB, __VA_ARGS__)
#define _glMultiTexCoord2dv(...) \
    callWithGLCheck(glMultiTexCoord2dv, __VA_ARGS__)
#define _glMultiTexCoord2dvARB(...) \
    callWithGLCheck(glMultiTexCoord2dvARB, __VA_ARGS__)
#define _glMultiTexCoord2f(...) callWithGLCheck(glMultiTexCoord2f, __VA_ARGS__)
#define _glMultiTexCoord2fARB(...) \
    callWithGLCheck(glMultiTexCoord2fARB, __VA_ARGS__)
#define _glMultiTexCoord2fv(...) \
    callWithGLCheck(glMultiTexCoord2fv, __VA_ARGS__)
#define _glMultiTexCoord2fvARB(...) \
    callWithGLCheck(glMultiTexCoord2fvARB, __VA_ARGS__)
#define _glMultiTexCoord2i(...) callWithGLCheck(glMultiTexCoord2i, __VA_ARGS__)
#define _glMultiTexCoord2iARB(...) \
    callWithGLCheck(glMultiTexCoord2iARB, __VA_ARGS__)
#define _glMultiTexCoord2iv(...) \
    callWithGLCheck(glMultiTexCoord2iv, __VA_ARGS__)
#define _glMultiTexCoord2ivARB(...) \
    callWithGLCheck(glMultiTexCoord2ivARB, __VA_ARGS__)
#define _glMultiTexCoord2s(...) callWithGLCheck(glMultiTexCoord2s, __VA_ARGS__)
#define _glMultiTexCoord2sARB(...) \
    callWithGLCheck(glMultiTexCoord2sARB, __VA_ARGS__)
#define _glMultiTexCoord2sv(...) \
    callWithGLCheck(glMultiTexCoord2sv, __VA_ARGS__)
#define _glMultiTexCoord2svARB(...) \
    callWithGLCheck(glMultiTexCoord2svARB, __VA_ARGS__)
#define _glMultiTexCoord3d(...) callWithGLCheck(glMultiTexCoord3d, __VA_ARGS__)
#define _glMultiTexCoord3dARB(...) \
    callWithGLCheck(glMultiTexCoord3dARB, __VA_ARGS__)
#define _glMultiTexCoord3dv(...) \
    callWithGLCheck(glMultiTexCoord3dv, __VA_ARGS__)
#define _glMultiTexCoord3dvARB(...) \
    callWithGLCheck(glMultiTexCoord3dvARB, __VA_ARGS__)
#define _glMultiTexCoord3f(...) callWithGLCheck(glMultiTexCoord3f, __VA_ARGS__)
#define _glMultiTexCoord3fARB(...) \
    callWithGLCheck(glMultiTexCoord3fARB, __VA_ARGS__)
#define _glMultiTexCoord3fv(...) \
    callWithGLCheck(glMultiTexCoord3fv, __VA_ARGS__)
#define _glMultiTexCoord3fvARB(...) \
    callWithGLCheck(glMultiTexCoord3fvARB, __VA_ARGS__)
#define _glMultiTexCoord3i(...) callWithGLCheck(glMultiTexCoord3i, __VA_ARGS__)
#define _glMultiTexCoord3iARB(...) \
    callWithGLCheck(glMultiTexCoord3iARB, __VA_ARGS__)
#define _glMultiTexCoord3iv(...) \
    callWithGLCheck(glMultiTexCoord3iv, __VA_ARGS__)
#define _glMultiTexCoord3ivARB(...) \
    callWithGLCheck(glMultiTexCoord3ivARB, __VA_ARGS__)
#define _glMultiTexCoord3s(...) callWithGLCheck(glMultiTexCoord3s, __VA_ARGS__)
#define _glMultiTexCoord3sARB(...) \
    callWithGLCheck(glMultiTexCoord3sARB, __VA_ARGS__)
#define _glMultiTexCoord3sv(...) \
    callWithGLCheck(glMultiTexCoord3sv, __VA_ARGS__)
#define _glMultiTexCoord3svARB(...) \
    callWithGLCheck(glMultiTexCoord3svARB, __VA_ARGS__)
#define _glMultiTexCoord4d(...) callWithGLCheck(glMultiTexCoord4d, __VA_ARGS__)
#define _glMultiTexCoord4dARB(...) \
    callWithGLCheck(glMultiTexCoord4dARB, __VA_ARGS__)
#define _glMultiTexCoord4dv(...) \
    callWithGLCheck(glMultiTexCoord4dv, __VA_ARGS__)
#define _glMultiTexCoord4dvARB(...) \
    callWithGLCheck(glMultiTexCoord4dvARB, __VA_ARGS__)
#define _glMultiTexCoord4f(...) callWithGLCheck(glMultiTexCoord4f, __VA_ARGS__)
#define _glMultiTexCoord4fARB(...) \
    callWithGLCheck(glMultiTexCoord4fARB, __VA_ARGS__)
#define _glMultiTexCoord4fv(...) \
    callWithGLCheck(glMultiTexCoord4fv, __VA_ARGS__)
#define _glMultiTexCoord4fvARB(...) \
    callWithGLCheck(glMultiTexCoord4fvARB, __VA_ARGS__)
#define _glMultiTexCoord4i(...) callWithGLCheck(glMultiTexCoord4i, __VA_ARGS__)
#define _glMultiTexCoord4iARB(...) \
    callWithGLCheck(glMultiTexCoord4iARB, __VA_ARGS__)
#define _glMultiTexCoord4iv(...) \
    callWithGLCheck(glMultiTexCoord4iv, __VA_ARGS__)
#define _glMultiTexCoord4ivARB(...) \
    callWithGLCheck(glMultiTexCoord4ivARB, __VA_ARGS__)
#define _glMultiTexCoord4s(...) callWithGLCheck(glMultiTexCoord4s, __VA_ARGS__)
#define _glMultiTexCoord4sARB(...) \
    callWithGLCheck(glMultiTexCoord4sARB, __VA_ARGS__)
#define _glMultiTexCoord4sv(...) \
    callWithGLCheck(glMultiTexCoord4sv, __VA_ARGS__)
#define _glMultiTexCoord4svARB(...) \
    callWithGLCheck(glMultiTexCoord4svARB, __VA_ARGS__)
#define _glNewList(...) callWithGLCheck(glNewList, __VA_ARGS__)
#define _glNormal3b(...) callWithGLCheck(glNormal3b, __VA_ARGS__)
#define _glNormal3bv(...) callWithGLCheck(glNormal3bv, __VA_ARGS__)
#define _glNormal3d(...) callWithGLCheck(glNormal3d, __VA_ARGS__)
#define _glNormal3dv(...) callWithGLCheck(glNormal3dv, __VA_ARGS__)
#define _glNormal3f(...) callWithGLCheck(glNormal3f, __VA_ARGS__)
#define _glNormal3fv(...) callWithGLCheck(glNormal3fv, __VA_ARGS__)
#define _glNormal3i(...) callWithGLCheck(glNormal3i, __VA_ARGS__)
#define _glNormal3iv(...) callWithGLCheck(glNormal3iv, __VA_ARGS__)
#define _glNormal3s(...) callWithGLCheck(glNormal3s, __VA_ARGS__)
#define _glNormal3sv(...) callWithGLCheck(glNormal3sv, __VA_ARGS__)
#define _glNormalPointer(...) callWithGLCheck(glNormalPointer, __VA_ARGS__)
#define _glObjectPurgeableAPPLE(...) \
    callWithGLCheck(glObjectPurgeableAPPLE, __VA_ARGS__)
#define _glObjectUnpurgeableAPPLE(...) \
    callWithGLCheck(glObjectUnpurgeableAPPLE, __VA_ARGS__)
#define _glOrtho(...) callWithGLCheck(glOrtho, __VA_ARGS__)
#define _glPassThrough(...) callWithGLCheck(glPassThrough, __VA_ARGS__)
#define _glPixelMapfv(...) callWithGLCheck(glPixelMapfv, __VA_ARGS__)
#define _glPixelMapuiv(...) callWithGLCheck(glPixelMapuiv, __VA_ARGS__)
#define _glPixelMapusv(...) callWithGLCheck(glPixelMapusv, __VA_ARGS__)
#define _glPixelStoref(...) callWithGLCheck(glPixelStoref, __VA_ARGS__)
#define _glPixelStorei(...) callWithGLCheck(glPixelStorei, __VA_ARGS__)
#define _glPixelTransferf(...) callWithGLCheck(glPixelTransferf, __VA_ARGS__)
#define _glPixelTransferi(...) callWithGLCheck(glPixelTransferi, __VA_ARGS__)
#define _glPixelZoom(...) callWithGLCheck(glPixelZoom, __VA_ARGS__)
#define _glPointParameterf(...) callWithGLCheck(glPointParameterf, __VA_ARGS__)
#define _glPointParameterfARB(...) \
    callWithGLCheck(glPointParameterfARB, __VA_ARGS__)
#define _glPointParameterfv(...) \
    callWithGLCheck(glPointParameterfv, __VA_ARGS__)
#define _glPointParameterfvARB(...) \
    callWithGLCheck(glPointParameterfvARB, __VA_ARGS__)
#define _glPointParameteri(...) callWithGLCheck(glPointParameteri, __VA_ARGS__)
#define _glPointParameteriNV(...) \
    callWithGLCheck(glPointParameteriNV, __VA_ARGS__)
#define _glPointParameteriv(...) \
    callWithGLCheck(glPointParameteriv, __VA_ARGS__)
#define _glPointParameterivNV(...) \
    callWithGLCheck(glPointParameterivNV, __VA_ARGS__)
#define _glPointSize(...) callWithGLCheck(glPointSize, __VA_ARGS__)
#define _glPointSizePointerAPPLE(...) \
    callWithGLCheck(glPointSizePointerAPPLE, __VA_ARGS__)
#define _glPolygonMode(...) callWithGLCheck(glPolygonMode, __VA_ARGS__)
#define _glPolygonOffset(...) callWithGLCheck(glPolygonOffset, __VA_ARGS__)
#define _glPolygonStipple(...) callWithGLCheck(glPolygonStipple, __VA_ARGS__)
#define _glPopAttrib(...) callWithGLCheck(glPopAttrib, __VA_ARGS__)
#define _glPopClientAttrib(...) callWithGLCheck(glPopClientAttrib, __VA_ARGS__)
#define _glPopGroupMarkerEXT(...) \
    callWithGLCheck(glPopGroupMarkerEXT, __VA_ARGS__)
#define _glPopMatrix(...) callWithGLCheck(glPopMatrix, __VA_ARGS__)
#define _glPopName(...) callWithGLCheck(glPopName, __VA_ARGS__)
#define _glPrioritizeTextures(...) \
    callWithGLCheck(glPrioritizeTextures, __VA_ARGS__)
#define _glProgramEnvParameter4dARB(...) \
    callWithGLCheck(glProgramEnvParameter4dARB, __VA_ARGS__)
#define _glProgramEnvParameter4dvARB(...) \
    callWithGLCheck(glProgramEnvParameter4dvARB, __VA_ARGS__)
#define _glProgramEnvParameter4fARB(...) \
    callWithGLCheck(glProgramEnvParameter4fARB, __VA_ARGS__)
#define _glProgramEnvParameter4fvARB(...) \
    callWithGLCheck(glProgramEnvParameter4fvARB, __VA_ARGS__)
#define _glProgramEnvParameters4fvEXT(...) \
    callWithGLCheck(glProgramEnvParameters4fvEXT, __VA_ARGS__)
#define _glProgramLocalParameter4dARB(...) \
    callWithGLCheck(glProgramLocalParameter4dARB, __VA_ARGS__)
#define _glProgramLocalParameter4dvARB(...) \
    callWithGLCheck(glProgramLocalParameter4dvARB, __VA_ARGS__)
#define _glProgramLocalParameter4fARB(...) \
    callWithGLCheck(glProgramLocalParameter4fARB, __VA_ARGS__)
#define _glProgramLocalParameter4fvARB(...) \
    callWithGLCheck(glProgramLocalParameter4fvARB, __VA_ARGS__)
#define _glProgramLocalParameters4fvEXT(...) \
    callWithGLCheck(glProgramLocalParameters4fvEXT, __VA_ARGS__)
#define _glProgramParameteriEXT(...) \
    callWithGLCheck(glProgramParameteriEXT, __VA_ARGS__)
#define _glProgramStringARB(...) \
    callWithGLCheck(glProgramStringARB, __VA_ARGS__)
#define _glProvokingVertex(...) callWithGLCheck(glProvokingVertex, __VA_ARGS__)
#define _glProvokingVertexEXT(...) \
    callWithGLCheck(glProvokingVertexEXT, __VA_ARGS__)
#define _glPushAttrib(...) callWithGLCheck(glPushAttrib, __VA_ARGS__)
#define _glPushClientAttrib(...) \
    callWithGLCheck(glPushClientAttrib, __VA_ARGS__)
#define _glPushGroupMarkerEXT(...) \
    callWithGLCheck(glPushGroupMarkerEXT, __VA_ARGS__)
#define _glPushMatrix(...) callWithGLCheck(glPushMatrix, __VA_ARGS__)
#define _glPushName(...) callWithGLCheck(glPushName, __VA_ARGS__)
#define _glRasterPos2d(...) callWithGLCheck(glRasterPos2d, __VA_ARGS__)
#define _glRasterPos2dv(...) callWithGLCheck(glRasterPos2dv, __VA_ARGS__)
#define _glRasterPos2f(...) callWithGLCheck(glRasterPos2f, __VA_ARGS__)
#define _glRasterPos2fv(...) callWithGLCheck(glRasterPos2fv, __VA_ARGS__)
#define _glRasterPos2i(...) callWithGLCheck(glRasterPos2i, __VA_ARGS__)
#define _glRasterPos2iv(...) callWithGLCheck(glRasterPos2iv, __VA_ARGS__)
#define _glRasterPos2s(...) callWithGLCheck(glRasterPos2s, __VA_ARGS__)
#define _glRasterPos2sv(...) callWithGLCheck(glRasterPos2sv, __VA_ARGS__)
#define _glRasterPos3d(...) callWithGLCheck(glRasterPos3d, __VA_ARGS__)
#define _glRasterPos3dv(...) callWithGLCheck(glRasterPos3dv, __VA_ARGS__)
#define _glRasterPos3f(...) callWithGLCheck(glRasterPos3f, __VA_ARGS__)
#define _glRasterPos3fv(...) callWithGLCheck(glRasterPos3fv, __VA_ARGS__)
#define _glRasterPos3i(...) callWithGLCheck(glRasterPos3i, __VA_ARGS__)
#define _glRasterPos3iv(...) callWithGLCheck(glRasterPos3iv, __VA_ARGS__)
#define _glRasterPos3s(...) callWithGLCheck(glRasterPos3s, __VA_ARGS__)
#define _glRasterPos3sv(...) callWithGLCheck(glRasterPos3sv, __VA_ARGS__)
#define _glRasterPos4d(...) callWithGLCheck(glRasterPos4d, __VA_ARGS__)
#define _glRasterPos4dv(...) callWithGLCheck(glRasterPos4dv, __VA_ARGS__)
#define _glRasterPos4f(...) callWithGLCheck(glRasterPos4f, __VA_ARGS__)
#define _glRasterPos4fv(...) callWithGLCheck(glRasterPos4fv, __VA_ARGS__)
#define _glRasterPos4i(...) callWithGLCheck(glRasterPos4i, __VA_ARGS__)
#define _glRasterPos4iv(...) callWithGLCheck(glRasterPos4iv, __VA_ARGS__)
#define _glRasterPos4s(...) callWithGLCheck(glRasterPos4s, __VA_ARGS__)
#define _glRasterPos4sv(...) callWithGLCheck(glRasterPos4sv, __VA_ARGS__)
#define _glReadBuffer(...) callWithGLCheck(glReadBuffer, __VA_ARGS__)
#define _glReadPixels(...) callWithGLCheck(glReadPixels, __VA_ARGS__)
#define _glRectd(...) callWithGLCheck(glRectd, __VA_ARGS__)
#define _glRectdv(...) callWithGLCheck(glRectdv, __VA_ARGS__)
#define _glRectf(...) callWithGLCheck(glRectf, __VA_ARGS__)
#define _glRectfv(...) callWithGLCheck(glRectfv, __VA_ARGS__)
#define _glRecti(...) callWithGLCheck(glRecti, __VA_ARGS__)
#define _glRectiv(...) callWithGLCheck(glRectiv, __VA_ARGS__)
#define _glRects(...) callWithGLCheck(glRects, __VA_ARGS__)
#define _glRectsv(...) callWithGLCheck(glRectsv, __VA_ARGS__)
#define _glRenderMode(...) callWithGLCheck(glRenderMode, __VA_ARGS__)
#define _glRenderbufferStorage(...) \
    callWithGLCheck(glRenderbufferStorage, __VA_ARGS__)
#define _glRenderbufferStorageEXT(...) \
    callWithGLCheck(glRenderbufferStorageEXT, __VA_ARGS__)
#define _glRenderbufferStorageMultisample(...) \
    callWithGLCheck(glRenderbufferStorageMultisample, __VA_ARGS__)
#define _glRenderbufferStorageMultisampleEXT(...) \
    callWithGLCheck(glRenderbufferStorageMultisampleEXT, __VA_ARGS__)
#define _glResetHistogram(...) callWithGLCheck(glResetHistogram, __VA_ARGS__)
#define _glResetMinmax(...) callWithGLCheck(glResetMinmax, __VA_ARGS__)
#define _glRotated(...) callWithGLCheck(glRotated, __VA_ARGS__)
#define _glRotatef(...) callWithGLCheck(glRotatef, __VA_ARGS__)
#define _glSampleCoverage(...) callWithGLCheck(glSampleCoverage, __VA_ARGS__)
#define _glSampleCoverageARB(...) \
    callWithGLCheck(glSampleCoverageARB, __VA_ARGS__)
#define _glScaled(...) callWithGLCheck(glScaled, __VA_ARGS__)
#define _glScalef(...) callWithGLCheck(glScalef, __VA_ARGS__)
#define _glScissor(...) callWithGLCheck(glScissor, __VA_ARGS__)
#define _glSecondaryColor3b(...) \
    callWithGLCheck(glSecondaryColor3b, __VA_ARGS__)
#define _glSecondaryColor3bEXT(...) \
    callWithGLCheck(glSecondaryColor3bEXT, __VA_ARGS__)
#define _glSecondaryColor3bv(...) \
    callWithGLCheck(glSecondaryColor3bv, __VA_ARGS__)
#define _glSecondaryColor3bvEXT(...) \
    callWithGLCheck(glSecondaryColor3bvEXT, __VA_ARGS__)
#define _glSecondaryColor3d(...) \
    callWithGLCheck(glSecondaryColor3d, __VA_ARGS__)
#define _glSecondaryColor3dEXT(...) \
    callWithGLCheck(glSecondaryColor3dEXT, __VA_ARGS__)
#define _glSecondaryColor3dv(...) \
    callWithGLCheck(glSecondaryColor3dv, __VA_ARGS__)
#define _glSecondaryColor3dvEXT(...) \
    callWithGLCheck(glSecondaryColor3dvEXT, __VA_ARGS__)
#define _glSecondaryColor3f(...) \
    callWithGLCheck(glSecondaryColor3f, __VA_ARGS__)
#define _glSecondaryColor3fEXT(...) \
    callWithGLCheck(glSecondaryColor3fEXT, __VA_ARGS__)
#define _glSecondaryColor3fv(...) \
    callWithGLCheck(glSecondaryColor3fv, __VA_ARGS__)
#define _glSecondaryColor3fvEXT(...) \
    callWithGLCheck(glSecondaryColor3fvEXT, __VA_ARGS__)
#define _glSecondaryColor3i(...) \
    callWithGLCheck(glSecondaryColor3i, __VA_ARGS__)
#define _glSecondaryColor3iEXT(...) \
    callWithGLCheck(glSecondaryColor3iEXT, __VA_ARGS__)
#define _glSecondaryColor3iv(...) \
    callWithGLCheck(glSecondaryColor3iv, __VA_ARGS__)
#define _glSecondaryColor3ivEXT(...) \
    callWithGLCheck(glSecondaryColor3ivEXT, __VA_ARGS__)
#define _glSecondaryColor3s(...) \
    callWithGLCheck(glSecondaryColor3s, __VA_ARGS__)
#define _glSecondaryColor3sEXT(...) \
    callWithGLCheck(glSecondaryColor3sEXT, __VA_ARGS__)
#define _glSecondaryColor3sv(...) \
    callWithGLCheck(glSecondaryColor3sv, __VA_ARGS__)
#define _glSecondaryColor3svEXT(...) \
    callWithGLCheck(glSecondaryColor3svEXT, __VA_ARGS__)
#define _glSecondaryColor3ub(...) \
    callWithGLCheck(glSecondaryColor3ub, __VA_ARGS__)
#define _glSecondaryColor3ubEXT(...) \
    callWithGLCheck(glSecondaryColor3ubEXT, __VA_ARGS__)
#define _glSecondaryColor3ubv(...) \
    callWithGLCheck(glSecondaryColor3ubv, __VA_ARGS__)
#define _glSecondaryColor3ubvEXT(...) \
    callWithGLCheck(glSecondaryColor3ubvEXT, __VA_ARGS__)
#define _glSecondaryColor3ui(...) \
    callWithGLCheck(glSecondaryColor3ui, __VA_ARGS__)
#define _glSecondaryColor3uiEXT(...) \
    callWithGLCheck(glSecondaryColor3uiEXT, __VA_ARGS__)
#define _glSecondaryColor3uiv(...) \
    callWithGLCheck(glSecondaryColor3uiv, __VA_ARGS__)
#define _glSecondaryColor3uivEXT(...) \
    callWithGLCheck(glSecondaryColor3uivEXT, __VA_ARGS__)
#define _glSecondaryColor3us(...) \
    callWithGLCheck(glSecondaryColor3us, __VA_ARGS__)
#define _glSecondaryColor3usEXT(...) \
    callWithGLCheck(glSecondaryColor3usEXT, __VA_ARGS__)
#define _glSecondaryColor3usv(...) \
    callWithGLCheck(glSecondaryColor3usv, __VA_ARGS__)
#define _glSecondaryColor3usvEXT(...) \
    callWithGLCheck(glSecondaryColor3usvEXT, __VA_ARGS__)
#define _glSecondaryColorPointer(...) \
    callWithGLCheck(glSecondaryColorPointer, __VA_ARGS__)
#define _glSecondaryColorPointerEXT(...) \
    callWithGLCheck(glSecondaryColorPointerEXT, __VA_ARGS__)
#define _glSelectBuffer(...) callWithGLCheck(glSelectBuffer, __VA_ARGS__)
#define _glSeparableFilter2D(...) \
    callWithGLCheck(glSeparableFilter2D, __VA_ARGS__)
#define _glSetFenceAPPLE(...) callWithGLCheck(glSetFenceAPPLE, __VA_ARGS__)
#define _glShadeModel(...) callWithGLCheck(glShadeModel, __VA_ARGS__)
#define _glShaderSource(...) callWithGLCheck(glShaderSource, __VA_ARGS__)
#define _glShaderSourceARB(...) callWithGLCheck(glShaderSourceARB, __VA_ARGS__)
#define _glStencilFunc(...) callWithGLCheck(glStencilFunc, __VA_ARGS__)
#define _glStencilFuncSeparate(...) \
    callWithGLCheck(glStencilFuncSeparate, __VA_ARGS__)
#define _glStencilFuncSeparateATI(...) \
    callWithGLCheck(glStencilFuncSeparateATI, __VA_ARGS__)
#define _glStencilMask(...) callWithGLCheck(glStencilMask, __VA_ARGS__)
#define _glStencilMaskSeparate(...) \
    callWithGLCheck(glStencilMaskSeparate, __VA_ARGS__)
#define _glStencilOp(...) callWithGLCheck(glStencilOp, __VA_ARGS__)
#define _glStencilOpSeparate(...) \
    callWithGLCheck(glStencilOpSeparate, __VA_ARGS__)
#define _glStencilOpSeparateATI(...) \
    callWithGLCheck(glStencilOpSeparateATI, __VA_ARGS__)
#define _glSwapAPPLE(...) callWithGLCheck(glSwapAPPLE, __VA_ARGS__)
#define _glTestFenceAPPLE(...) callWithGLCheck(glTestFenceAPPLE, __VA_ARGS__)
#define _glTestObjectAPPLE(...) callWithGLCheck(glTestObjectAPPLE, __VA_ARGS__)
#define _glTexCoord1d(...) callWithGLCheck(glTexCoord1d, __VA_ARGS__)
#define _glTexCoord1dv(...) callWithGLCheck(glTexCoord1dv, __VA_ARGS__)
#define _glTexCoord1f(...) callWithGLCheck(glTexCoord1f, __VA_ARGS__)
#define _glTexCoord1fv(...) callWithGLCheck(glTexCoord1fv, __VA_ARGS__)
#define _glTexCoord1i(...) callWithGLCheck(glTexCoord1i, __VA_ARGS__)
#define _glTexCoord1iv(...) callWithGLCheck(glTexCoord1iv, __VA_ARGS__)
#define _glTexCoord1s(...) callWithGLCheck(glTexCoord1s, __VA_ARGS__)
#define _glTexCoord1sv(...) callWithGLCheck(glTexCoord1sv, __VA_ARGS__)
#define _glTexCoord2d(...) callWithGLCheck(glTexCoord2d, __VA_ARGS__)
#define _glTexCoord2dv(...) callWithGLCheck(glTexCoord2dv, __VA_ARGS__)
#define _glTexCoord2f(...) callWithGLCheck(glTexCoord2f, __VA_ARGS__)
#define _glTexCoord2fv(...) callWithGLCheck(glTexCoord2fv, __VA_ARGS__)
#define _glTexCoord2i(...) callWithGLCheck(glTexCoord2i, __VA_ARGS__)
#define _glTexCoord2iv(...) callWithGLCheck(glTexCoord2iv, __VA_ARGS__)
#define _glTexCoord2s(...) callWithGLCheck(glTexCoord2s, __VA_ARGS__)
#define _glTexCoord2sv(...) callWithGLCheck(glTexCoord2sv, __VA_ARGS__)
#define _glTexCoord3d(...) callWithGLCheck(glTexCoord3d, __VA_ARGS__)
#define _glTexCoord3dv(...) callWithGLCheck(glTexCoord3dv, __VA_ARGS__)
#define _glTexCoord3f(...) callWithGLCheck(glTexCoord3f, __VA_ARGS__)
#define _glTexCoord3fv(...) callWithGLCheck(glTexCoord3fv, __VA_ARGS__)
#define _glTexCoord3i(...) callWithGLCheck(glTexCoord3i, __VA_ARGS__)
#define _glTexCoord3iv(...) callWithGLCheck(glTexCoord3iv, __VA_ARGS__)
#define _glTexCoord3s(...) callWithGLCheck(glTexCoord3s, __VA_ARGS__)
#define _glTexCoord3sv(...) callWithGLCheck(glTexCoord3sv, __VA_ARGS__)
#define _glTexCoord4d(...) callWithGLCheck(glTexCoord4d, __VA_ARGS__)
#define _glTexCoord4dv(...) callWithGLCheck(glTexCoord4dv, __VA_ARGS__)
#define _glTexCoord4f(...) callWithGLCheck(glTexCoord4f, __VA_ARGS__)
#define _glTexCoord4fv(...) callWithGLCheck(glTexCoord4fv, __VA_ARGS__)
#define _glTexCoord4i(...) callWithGLCheck(glTexCoord4i, __VA_ARGS__)
#define _glTexCoord4iv(...) callWithGLCheck(glTexCoord4iv, __VA_ARGS__)
#define _glTexCoord4s(...) callWithGLCheck(glTexCoord4s, __VA_ARGS__)
#define _glTexCoord4sv(...) callWithGLCheck(glTexCoord4sv, __VA_ARGS__)
#define _glTexCoordPointer(...) callWithGLCheck(glTexCoordPointer, __VA_ARGS__)
#define _glTexEnvf(...) callWithGLCheck(glTexEnvf, __VA_ARGS__)
#define _glTexEnvfv(...) callWithGLCheck(glTexEnvfv, __VA_ARGS__)
#define _glTexEnvi(...) callWithGLCheck(glTexEnvi, __VA_ARGS__)
#define _glTexEnviv(...) callWithGLCheck(glTexEnviv, __VA_ARGS__)
#define _glTexGend(...) callWithGLCheck(glTexGend, __VA_ARGS__)
#define _glTexGendv(...) callWithGLCheck(glTexGendv, __VA_ARGS__)
#define _glTexGenf(...) callWithGLCheck(glTexGenf, __VA_ARGS__)
#define _glTexGenfv(...) callWithGLCheck(glTexGenfv, __VA_ARGS__)
#define _glTexGeni(...) callWithGLCheck(glTexGeni, __VA_ARGS__)
#define _glTexGeniv(...) callWithGLCheck(glTexGeniv, __VA_ARGS__)
#define _glTexImage1D(...) callWithGLCheck(glTexImage1D, __VA_ARGS__)
#define _glTexImage2D(...) callWithGLCheck(glTexImage2D, __VA_ARGS__)
#define _glTexImage3D(...) callWithGLCheck(glTexImage3D, __VA_ARGS__)
#define _glTexParameterIiv(...) callWithGLCheck(glTexParameterIiv, __VA_ARGS__)
#define _glTexParameterIivEXT(...) \
    callWithGLCheck(glTexParameterIivEXT, __VA_ARGS__)
#define _glTexParameterIuiv(...) \
    callWithGLCheck(glTexParameterIuiv, __VA_ARGS__)
#define _glTexParameterIuivEXT(...) \
    callWithGLCheck(glTexParameterIuivEXT, __VA_ARGS__)
#define _glTexParameterf(...) callWithGLCheck(glTexParameterf, __VA_ARGS__)
#define _glTexParameterfv(...) callWithGLCheck(glTexParameterfv, __VA_ARGS__)
#define _glTexParameteri(...) callWithGLCheck(glTexParameteri, __VA_ARGS__)
#define _glTexParameteriv(...) callWithGLCheck(glTexParameteriv, __VA_ARGS__)
#define _glTexSubImage1D(...) callWithGLCheck(glTexSubImage1D, __VA_ARGS__)
#define _glTexSubImage2D(...) callWithGLCheck(glTexSubImage2D, __VA_ARGS__)
#define _glTexSubImage3D(...) callWithGLCheck(glTexSubImage3D, __VA_ARGS__)
#define _glTextureBarrierNV(...) \
    callWithGLCheck(glTextureBarrierNV, __VA_ARGS__)
#define _glTextureRangeAPPLE(...) \
    callWithGLCheck(glTextureRangeAPPLE, __VA_ARGS__)
#define _glTransformFeedbackVaryings(...) \
    callWithGLCheck(glTransformFeedbackVaryings, __VA_ARGS__)
#define _glTransformFeedbackVaryingsEXT(...) \
    callWithGLCheck(glTransformFeedbackVaryingsEXT, __VA_ARGS__)
#define _glTranslated(...) callWithGLCheck(glTranslated, __VA_ARGS__)
#define _glTranslatef(...) callWithGLCheck(glTranslatef, __VA_ARGS__)
#define _glUniform1f(...) callWithGLCheck(glUniform1f, __VA_ARGS__)
#define _glUniform1fARB(...) callWithGLCheck(glUniform1fARB, __VA_ARGS__)
#define _glUniform1fv(...) callWithGLCheck(glUniform1fv, __VA_ARGS__)
#define _glUniform1fvARB(...) callWithGLCheck(glUniform1fvARB, __VA_ARGS__)
#define _glUniform1i(...) callWithGLCheck(glUniform1i, __VA_ARGS__)
#define _glUniform1iARB(...) callWithGLCheck(glUniform1iARB, __VA_ARGS__)
#define _glUniform1iv(...) callWithGLCheck(glUniform1iv, __VA_ARGS__)
#define _glUniform1ivARB(...) callWithGLCheck(glUniform1ivARB, __VA_ARGS__)
#define _glUniform1ui(...) callWithGLCheck(glUniform1ui, __VA_ARGS__)
#define _glUniform1uiEXT(...) callWithGLCheck(glUniform1uiEXT, __VA_ARGS__)
#define _glUniform1uiv(...) callWithGLCheck(glUniform1uiv, __VA_ARGS__)
#define _glUniform1uivEXT(...) callWithGLCheck(glUniform1uivEXT, __VA_ARGS__)
#define _glUniform2f(...) callWithGLCheck(glUniform2f, __VA_ARGS__)
#define _glUniform2fARB(...) callWithGLCheck(glUniform2fARB, __VA_ARGS__)
#define _glUniform2fv(...) callWithGLCheck(glUniform2fv, __VA_ARGS__)
#define _glUniform2fvARB(...) callWithGLCheck(glUniform2fvARB, __VA_ARGS__)
#define _glUniform2i(...) callWithGLCheck(glUniform2i, __VA_ARGS__)
#define _glUniform2iARB(...) callWithGLCheck(glUniform2iARB, __VA_ARGS__)
#define _glUniform2iv(...) callWithGLCheck(glUniform2iv, __VA_ARGS__)
#define _glUniform2ivARB(...) callWithGLCheck(glUniform2ivARB, __VA_ARGS__)
#define _glUniform2ui(...) callWithGLCheck(glUniform2ui, __VA_ARGS__)
#define _glUniform2uiEXT(...) callWithGLCheck(glUniform2uiEXT, __VA_ARGS__)
#define _glUniform2uiv(...) callWithGLCheck(glUniform2uiv, __VA_ARGS__)
#define _glUniform2uivEXT(...) callWithGLCheck(glUniform2uivEXT, __VA_ARGS__)
#define _glUniform3f(...) callWithGLCheck(glUniform3f, __VA_ARGS__)
#define _glUniform3fARB(...) callWithGLCheck(glUniform3fARB, __VA_ARGS__)
#define _glUniform3fv(...) callWithGLCheck(glUniform3fv, __VA_ARGS__)
#define _glUniform3fvARB(...) callWithGLCheck(glUniform3fvARB, __VA_ARGS__)
#define _glUniform3i(...) callWithGLCheck(glUniform3i, __VA_ARGS__)
#define _glUniform3iARB(...) callWithGLCheck(glUniform3iARB, __VA_ARGS__)
#define _glUniform3iv(...) callWithGLCheck(glUniform3iv, __VA_ARGS__)
#define _glUniform3ivARB(...) callWithGLCheck(glUniform3ivARB, __VA_ARGS__)
#define _glUniform3ui(...) callWithGLCheck(glUniform3ui, __VA_ARGS__)
#define _glUniform3uiEXT(...) callWithGLCheck(glUniform3uiEXT, __VA_ARGS__)
#define _glUniform3uiv(...) callWithGLCheck(glUniform3uiv, __VA_ARGS__)
#define _glUniform3uivEXT(...) callWithGLCheck(glUniform3uivEXT, __VA_ARGS__)
#define _glUniform4f(...) callWithGLCheck(glUniform4f, __VA_ARGS__)
#define _glUniform4fARB(...) callWithGLCheck(glUniform4fARB, __VA_ARGS__)
#define _glUniform4fv(...) callWithGLCheck(glUniform4fv, __VA_ARGS__)
#define _glUniform4fvARB(...) callWithGLCheck(glUniform4fvARB, __VA_ARGS__)
#define _glUniform4i(...) callWithGLCheck(glUniform4i, __VA_ARGS__)
#define _glUniform4iARB(...) callWithGLCheck(glUniform4iARB, __VA_ARGS__)
#define _glUniform4iv(...) callWithGLCheck(glUniform4iv, __VA_ARGS__)
#define _glUniform4ivARB(...) callWithGLCheck(glUniform4ivARB, __VA_ARGS__)
#define _glUniform4ui(...) callWithGLCheck(glUniform4ui, __VA_ARGS__)
#define _glUniform4uiEXT(...) callWithGLCheck(glUniform4uiEXT, __VA_ARGS__)
#define _glUniform4uiv(...) callWithGLCheck(glUniform4uiv, __VA_ARGS__)
#define _glUniform4uivEXT(...) callWithGLCheck(glUniform4uivEXT, __VA_ARGS__)
#define _glUniformBufferEXT(...) \
    callWithGLCheck(glUniformBufferEXT, __VA_ARGS__)
#define _glUniformMatrix2fv(...) \
    callWithGLCheck(glUniformMatrix2fv, __VA_ARGS__)
#define _glUniformMatrix2fvARB(...) \
    callWithGLCheck(glUniformMatrix2fvARB, __VA_ARGS__)
#define _glUniformMatrix2x3fv(...) \
    callWithGLCheck(glUniformMatrix2x3fv, __VA_ARGS__)
#define _glUniformMatrix2x4fv(...) \
    callWithGLCheck(glUniformMatrix2x4fv, __VA_ARGS__)
#define _glUniformMatrix3fv(...) \
    callWithGLCheck(glUniformMatrix3fv, __VA_ARGS__)
#define _glUniformMatrix3fvARB(...) \
    callWithGLCheck(glUniformMatrix3fvARB, __VA_ARGS__)
#define _glUniformMatrix3x2fv(...) \
    callWithGLCheck(glUniformMatrix3x2fv, __VA_ARGS__)
#define _glUniformMatrix3x4fv(...) \
    callWithGLCheck(glUniformMatrix3x4fv, __VA_ARGS__)
#define _glUniformMatrix4fv(...) \
    callWithGLCheck(glUniformMatrix4fv, __VA_ARGS__)
#define _glUniformMatrix4fvARB(...) \
    callWithGLCheck(glUniformMatrix4fvARB, __VA_ARGS__)
#define _glUniformMatrix4x2fv(...) \
    callWithGLCheck(glUniformMatrix4x2fv, __VA_ARGS__)
#define _glUniformMatrix4x3fv(...) \
    callWithGLCheck(glUniformMatrix4x3fv, __VA_ARGS__)
#define _glUnmapBuffer(...) callWithGLCheck(glUnmapBuffer, __VA_ARGS__)
#define _glUnmapBufferARB(...) callWithGLCheck(glUnmapBufferARB, __VA_ARGS__)
#define _glUseProgram(...) callWithGLCheck(glUseProgram, __VA_ARGS__)
#define _glUseProgramObjectARB(...) \
    callWithGLCheck(glUseProgramObjectARB, __VA_ARGS__)
#define _glValidateProgram(...) callWithGLCheck(glValidateProgram, __VA_ARGS__)
#define _glValidateProgramARB(...) \
    callWithGLCheck(glValidateProgramARB, __VA_ARGS__)
#define _glVertex2d(...) callWithGLCheck(glVertex2d, __VA_ARGS__)
#define _glVertex2dv(...) callWithGLCheck(glVertex2dv, __VA_ARGS__)
#define _glVertex2f(...) callWithGLCheck(glVertex2f, __VA_ARGS__)
#define _glVertex2fv(...) callWithGLCheck(glVertex2fv, __VA_ARGS__)
#define _glVertex2i(...) callWithGLCheck(glVertex2i, __VA_ARGS__)
#define _glVertex2iv(...) callWithGLCheck(glVertex2iv, __VA_ARGS__)
#define _glVertex2s(...) callWithGLCheck(glVertex2s, __VA_ARGS__)
#define _glVertex2sv(...) callWithGLCheck(glVertex2sv, __VA_ARGS__)
#define _glVertex3d(...) callWithGLCheck(glVertex3d, __VA_ARGS__)
#define _glVertex3dv(...) callWithGLCheck(glVertex3dv, __VA_ARGS__)
#define _glVertex3f(...) callWithGLCheck(glVertex3f, __VA_ARGS__)
#define _glVertex3fv(...) callWithGLCheck(glVertex3fv, __VA_ARGS__)
#define _glVertex3i(...) callWithGLCheck(glVertex3i, __VA_ARGS__)
#define _glVertex3iv(...) callWithGLCheck(glVertex3iv, __VA_ARGS__)
#define _glVertex3s(...) callWithGLCheck(glVertex3s, __VA_ARGS__)
#define _glVertex3sv(...) callWithGLCheck(glVertex3sv, __VA_ARGS__)
#define _glVertex4d(...) callWithGLCheck(glVertex4d, __VA_ARGS__)
#define _glVertex4dv(...) callWithGLCheck(glVertex4dv, __VA_ARGS__)
#define _glVertex4f(...) callWithGLCheck(glVertex4f, __VA_ARGS__)
#define _glVertex4fv(...) callWithGLCheck(glVertex4fv, __VA_ARGS__)
#define _glVertex4i(...) callWithGLCheck(glVertex4i, __VA_ARGS__)
#define _glVertex4iv(...) callWithGLCheck(glVertex4iv, __VA_ARGS__)
#define _glVertex4s(...) callWithGLCheck(glVertex4s, __VA_ARGS__)
#define _glVertex4sv(...) callWithGLCheck(glVertex4sv, __VA_ARGS__)
#define _glVertexArrayParameteriAPPLE(...) \
    callWithGLCheck(glVertexArrayParameteriAPPLE, __VA_ARGS__)
#define _glVertexArrayRangeAPPLE(...) \
    callWithGLCheck(glVertexArrayRangeAPPLE, __VA_ARGS__)
#define _glVertexAttrib1d(...) callWithGLCheck(glVertexAttrib1d, __VA_ARGS__)
#define _glVertexAttrib1dARB(...) \
    callWithGLCheck(glVertexAttrib1dARB, __VA_ARGS__)
#define _glVertexAttrib1dv(...) callWithGLCheck(glVertexAttrib1dv, __VA_ARGS__)
#define _glVertexAttrib1dvARB(...) \
    callWithGLCheck(glVertexAttrib1dvARB, __VA_ARGS__)
#define _glVertexAttrib1f(...) callWithGLCheck(glVertexAttrib1f, __VA_ARGS__)
#define _glVertexAttrib1fARB(...) \
    callWithGLCheck(glVertexAttrib1fARB, __VA_ARGS__)
#define _glVertexAttrib1fv(...) callWithGLCheck(glVertexAttrib1fv, __VA_ARGS__)
#define _glVertexAttrib1fvARB(...) \
    callWithGLCheck(glVertexAttrib1fvARB, __VA_ARGS__)
#define _glVertexAttrib1s(...) callWithGLCheck(glVertexAttrib1s, __VA_ARGS__)
#define _glVertexAttrib1sARB(...) \
    callWithGLCheck(glVertexAttrib1sARB, __VA_ARGS__)
#define _glVertexAttrib1sv(...) callWithGLCheck(glVertexAttrib1sv, __VA_ARGS__)
#define _glVertexAttrib1svARB(...) \
    callWithGLCheck(glVertexAttrib1svARB, __VA_ARGS__)
#define _glVertexAttrib2d(...) callWithGLCheck(glVertexAttrib2d, __VA_ARGS__)
#define _glVertexAttrib2dARB(...) \
    callWithGLCheck(glVertexAttrib2dARB, __VA_ARGS__)
#define _glVertexAttrib2dv(...) callWithGLCheck(glVertexAttrib2dv, __VA_ARGS__)
#define _glVertexAttrib2dvARB(...) \
    callWithGLCheck(glVertexAttrib2dvARB, __VA_ARGS__)
#define _glVertexAttrib2f(...) callWithGLCheck(glVertexAttrib2f, __VA_ARGS__)
#define _glVertexAttrib2fARB(...) \
    callWithGLCheck(glVertexAttrib2fARB, __VA_ARGS__)
#define _glVertexAttrib2fv(...) callWithGLCheck(glVertexAttrib2fv, __VA_ARGS__)
#define _glVertexAttrib2fvARB(...) \
    callWithGLCheck(glVertexAttrib2fvARB, __VA_ARGS__)
#define _glVertexAttrib2s(...) callWithGLCheck(glVertexAttrib2s, __VA_ARGS__)
#define _glVertexAttrib2sARB(...) \
    callWithGLCheck(glVertexAttrib2sARB, __VA_ARGS__)
#define _glVertexAttrib2sv(...) callWithGLCheck(glVertexAttrib2sv, __VA_ARGS__)
#define _glVertexAttrib2svARB(...) \
    callWithGLCheck(glVertexAttrib2svARB, __VA_ARGS__)
#define _glVertexAttrib3d(...) callWithGLCheck(glVertexAttrib3d, __VA_ARGS__)
#define _glVertexAttrib3dARB(...) \
    callWithGLCheck(glVertexAttrib3dARB, __VA_ARGS__)
#define _glVertexAttrib3dv(...) callWithGLCheck(glVertexAttrib3dv, __VA_ARGS__)
#define _glVertexAttrib3dvARB(...) \
    callWithGLCheck(glVertexAttrib3dvARB, __VA_ARGS__)
#define _glVertexAttrib3f(...) callWithGLCheck(glVertexAttrib3f, __VA_ARGS__)
#define _glVertexAttrib3fARB(...) \
    callWithGLCheck(glVertexAttrib3fARB, __VA_ARGS__)
#define _glVertexAttrib3fv(...) callWithGLCheck(glVertexAttrib3fv, __VA_ARGS__)
#define _glVertexAttrib3fvARB(...) \
    callWithGLCheck(glVertexAttrib3fvARB, __VA_ARGS__)
#define _glVertexAttrib3s(...) callWithGLCheck(glVertexAttrib3s, __VA_ARGS__)
#define _glVertexAttrib3sARB(...) \
    callWithGLCheck(glVertexAttrib3sARB, __VA_ARGS__)
#define _glVertexAttrib3sv(...) callWithGLCheck(glVertexAttrib3sv, __VA_ARGS__)
#define _glVertexAttrib3svARB(...) \
    callWithGLCheck(glVertexAttrib3svARB, __VA_ARGS__)
#define _glVertexAttrib4Nbv(...) \
    callWithGLCheck(glVertexAttrib4Nbv, __VA_ARGS__)
#define _glVertexAttrib4NbvARB(...) \
    callWithGLCheck(glVertexAttrib4NbvARB, __VA_ARGS__)
#define _glVertexAttrib4Niv(...) \
    callWithGLCheck(glVertexAttrib4Niv, __VA_ARGS__)
#define _glVertexAttrib4NivARB(...) \
    callWithGLCheck(glVertexAttrib4NivARB, __VA_ARGS__)
#define _glVertexAttrib4Nsv(...) \
    callWithGLCheck(glVertexAttrib4Nsv, __VA_ARGS__)
#define _glVertexAttrib4NsvARB(...) \
    callWithGLCheck(glVertexAttrib4NsvARB, __VA_ARGS__)
#define _glVertexAttrib4Nub(...) \
    callWithGLCheck(glVertexAttrib4Nub, __VA_ARGS__)
#define _glVertexAttrib4NubARB(...) \
    callWithGLCheck(glVertexAttrib4NubARB, __VA_ARGS__)
#define _glVertexAttrib4Nubv(...) \
    callWithGLCheck(glVertexAttrib4Nubv, __VA_ARGS__)
#define _glVertexAttrib4NubvARB(...) \
    callWithGLCheck(glVertexAttrib4NubvARB, __VA_ARGS__)
#define _glVertexAttrib4Nuiv(...) \
    callWithGLCheck(glVertexAttrib4Nuiv, __VA_ARGS__)
#define _glVertexAttrib4NuivARB(...) \
    callWithGLCheck(glVertexAttrib4NuivARB, __VA_ARGS__)
#define _glVertexAttrib4Nusv(...) \
    callWithGLCheck(glVertexAttrib4Nusv, __VA_ARGS__)
#define _glVertexAttrib4NusvARB(...) \
    callWithGLCheck(glVertexAttrib4NusvARB, __VA_ARGS__)
#define _glVertexAttrib4bv(...) callWithGLCheck(glVertexAttrib4bv, __VA_ARGS__)
#define _glVertexAttrib4bvARB(...) \
    callWithGLCheck(glVertexAttrib4bvARB, __VA_ARGS__)
#define _glVertexAttrib4d(...) callWithGLCheck(glVertexAttrib4d, __VA_ARGS__)
#define _glVertexAttrib4dARB(...) \
    callWithGLCheck(glVertexAttrib4dARB, __VA_ARGS__)
#define _glVertexAttrib4dv(...) callWithGLCheck(glVertexAttrib4dv, __VA_ARGS__)
#define _glVertexAttrib4dvARB(...) \
    callWithGLCheck(glVertexAttrib4dvARB, __VA_ARGS__)
#define _glVertexAttrib4f(...) callWithGLCheck(glVertexAttrib4f, __VA_ARGS__)
#define _glVertexAttrib4fARB(...) \
    callWithGLCheck(glVertexAttrib4fARB, __VA_ARGS__)
#define _glVertexAttrib4fv(...) callWithGLCheck(glVertexAttrib4fv, __VA_ARGS__)
#define _glVertexAttrib4fvARB(...) \
    callWithGLCheck(glVertexAttrib4fvARB, __VA_ARGS__)
#define _glVertexAttrib4iv(...) callWithGLCheck(glVertexAttrib4iv, __VA_ARGS__)
#define _glVertexAttrib4ivARB(...) \
    callWithGLCheck(glVertexAttrib4ivARB, __VA_ARGS__)
#define _glVertexAttrib4s(...) callWithGLCheck(glVertexAttrib4s, __VA_ARGS__)
#define _glVertexAttrib4sARB(...) \
    callWithGLCheck(glVertexAttrib4sARB, __VA_ARGS__)
#define _glVertexAttrib4sv(...) callWithGLCheck(glVertexAttrib4sv, __VA_ARGS__)
#define _glVertexAttrib4svARB(...) \
    callWithGLCheck(glVertexAttrib4svARB, __VA_ARGS__)
#define _glVertexAttrib4ubv(...) \
    callWithGLCheck(glVertexAttrib4ubv, __VA_ARGS__)
#define _glVertexAttrib4ubvARB(...) \
    callWithGLCheck(glVertexAttrib4ubvARB, __VA_ARGS__)
#define _glVertexAttrib4uiv(...) \
    callWithGLCheck(glVertexAttrib4uiv, __VA_ARGS__)
#define _glVertexAttrib4uivARB(...) \
    callWithGLCheck(glVertexAttrib4uivARB, __VA_ARGS__)
#define _glVertexAttrib4usv(...) \
    callWithGLCheck(glVertexAttrib4usv, __VA_ARGS__)
#define _glVertexAttrib4usvARB(...) \
    callWithGLCheck(glVertexAttrib4usvARB, __VA_ARGS__)
#define _glVertexAttribDivisorARB(...) \
    callWithGLCheck(glVertexAttribDivisorARB, __VA_ARGS__)
#define _glVertexAttribI1i(...) callWithGLCheck(glVertexAttribI1i, __VA_ARGS__)
#define _glVertexAttribI1iEXT(...) \
    callWithGLCheck(glVertexAttribI1iEXT, __VA_ARGS__)
#define _glVertexAttribI1iv(...) \
    callWithGLCheck(glVertexAttribI1iv, __VA_ARGS__)
#define _glVertexAttribI1ivEXT(...) \
    callWithGLCheck(glVertexAttribI1ivEXT, __VA_ARGS__)
#define _glVertexAttribI1ui(...) \
    callWithGLCheck(glVertexAttribI1ui, __VA_ARGS__)
#define _glVertexAttribI1uiEXT(...) \
    callWithGLCheck(glVertexAttribI1uiEXT, __VA_ARGS__)
#define _glVertexAttribI1uiv(...) \
    callWithGLCheck(glVertexAttribI1uiv, __VA_ARGS__)
#define _glVertexAttribI1uivEXT(...) \
    callWithGLCheck(glVertexAttribI1uivEXT, __VA_ARGS__)
#define _glVertexAttribI2i(...) callWithGLCheck(glVertexAttribI2i, __VA_ARGS__)
#define _glVertexAttribI2iEXT(...) \
    callWithGLCheck(glVertexAttribI2iEXT, __VA_ARGS__)
#define _glVertexAttribI2iv(...) \
    callWithGLCheck(glVertexAttribI2iv, __VA_ARGS__)
#define _glVertexAttribI2ivEXT(...) \
    callWithGLCheck(glVertexAttribI2ivEXT, __VA_ARGS__)
#define _glVertexAttribI2ui(...) \
    callWithGLCheck(glVertexAttribI2ui, __VA_ARGS__)
#define _glVertexAttribI2uiEXT(...) \
    callWithGLCheck(glVertexAttribI2uiEXT, __VA_ARGS__)
#define _glVertexAttribI2uiv(...) \
    callWithGLCheck(glVertexAttribI2uiv, __VA_ARGS__)
#define _glVertexAttribI2uivEXT(...) \
    callWithGLCheck(glVertexAttribI2uivEXT, __VA_ARGS__)
#define _glVertexAttribI3i(...) callWithGLCheck(glVertexAttribI3i, __VA_ARGS__)
#define _glVertexAttribI3iEXT(...) \
    callWithGLCheck(glVertexAttribI3iEXT, __VA_ARGS__)
#define _glVertexAttribI3iv(...) \
    callWithGLCheck(glVertexAttribI3iv, __VA_ARGS__)
#define _glVertexAttribI3ivEXT(...) \
    callWithGLCheck(glVertexAttribI3ivEXT, __VA_ARGS__)
#define _glVertexAttribI3ui(...) \
    callWithGLCheck(glVertexAttribI3ui, __VA_ARGS__)
#define _glVertexAttribI3uiEXT(...) \
    callWithGLCheck(glVertexAttribI3uiEXT, __VA_ARGS__)
#define _glVertexAttribI3uiv(...) \
    callWithGLCheck(glVertexAttribI3uiv, __VA_ARGS__)
#define _glVertexAttribI3uivEXT(...) \
    callWithGLCheck(glVertexAttribI3uivEXT, __VA_ARGS__)
#define _glVertexAttribI4bv(...) \
    callWithGLCheck(glVertexAttribI4bv, __VA_ARGS__)
#define _glVertexAttribI4bvEXT(...) \
    callWithGLCheck(glVertexAttribI4bvEXT, __VA_ARGS__)
#define _glVertexAttribI4i(...) callWithGLCheck(glVertexAttribI4i, __VA_ARGS__)
#define _glVertexAttribI4iEXT(...) \
    callWithGLCheck(glVertexAttribI4iEXT, __VA_ARGS__)
#define _glVertexAttribI4iv(...) \
    callWithGLCheck(glVertexAttribI4iv, __VA_ARGS__)
#define _glVertexAttribI4ivEXT(...) \
    callWithGLCheck(glVertexAttribI4ivEXT, __VA_ARGS__)
#define _glVertexAttribI4sv(...) \
    callWithGLCheck(glVertexAttribI4sv, __VA_ARGS__)
#define _glVertexAttribI4svEXT(...) \
    callWithGLCheck(glVertexAttribI4svEXT, __VA_ARGS__)
#define _glVertexAttribI4ubv(...) \
    callWithGLCheck(glVertexAttribI4ubv, __VA_ARGS__)
#define _glVertexAttribI4ubvEXT(...) \
    callWithGLCheck(glVertexAttribI4ubvEXT, __VA_ARGS__)
#define _glVertexAttribI4ui(...) \
    callWithGLCheck(glVertexAttribI4ui, __VA_ARGS__)
#define _glVertexAttribI4uiEXT(...) \
    callWithGLCheck(glVertexAttribI4uiEXT, __VA_ARGS__)
#define _glVertexAttribI4uiv(...) \
    callWithGLCheck(glVertexAttribI4uiv, __VA_ARGS__)
#define _glVertexAttribI4uivEXT(...) \
    callWithGLCheck(glVertexAttribI4uivEXT, __VA_ARGS__)
#define _glVertexAttribI4usv(...) \
    callWithGLCheck(glVertexAttribI4usv, __VA_ARGS__)
#define _glVertexAttribI4usvEXT(...) \
    callWithGLCheck(glVertexAttribI4usvEXT, __VA_ARGS__)
#define _glVertexAttribIPointer(...) \
    callWithGLCheck(glVertexAttribIPointer, __VA_ARGS__)
#define _glVertexAttribIPointerEXT(...) \
    callWithGLCheck(glVertexAttribIPointerEXT, __VA_ARGS__)
#define _glVertexAttribPointer(...) \
    callWithGLCheck(glVertexAttribPointer, __VA_ARGS__)
#define _glVertexAttribPointerARB(...) \
    callWithGLCheck(glVertexAttribPointerARB, __VA_ARGS__)
#define _glVertexBlendARB(...) callWithGLCheck(glVertexBlendARB, __VA_ARGS__)
#define _glVertexPointSizefAPPLE(...) \
    callWithGLCheck(glVertexPointSizefAPPLE, __VA_ARGS__)
#define _glVertexPointer(...) callWithGLCheck(glVertexPointer, __VA_ARGS__)
#define _glViewport(...) callWithGLCheck(glViewport, __VA_ARGS__)
#define _glWaitSync(...) callWithGLCheck(glWaitSync, __VA_ARGS__)
#define _glWeightPointerARB(...) \
    callWithGLCheck(glWeightPointerARB, __VA_ARGS__)
#define _glWeightbvARB(...) callWithGLCheck(glWeightbvARB, __VA_ARGS__)
#define _glWeightdvARB(...) callWithGLCheck(glWeightdvARB, __VA_ARGS__)
#define _glWeightfvARB(...) callWithGLCheck(glWeightfvARB, __VA_ARGS__)
#define _glWeightivARB(...) callWithGLCheck(glWeightivARB, __VA_ARGS__)
#define _glWeightsvARB(...) callWithGLCheck(glWeightsvARB, __VA_ARGS__)
#define _glWeightubvARB(...) callWithGLCheck(glWeightubvARB, __VA_ARGS__)
#define _glWeightuivARB(...) callWithGLCheck(glWeightuivARB, __VA_ARGS__)
#define _glWeightusvARB(...) callWithGLCheck(glWeightusvARB, __VA_ARGS__)
#define _glWindowPos2d(...) callWithGLCheck(glWindowPos2d, __VA_ARGS__)
#define _glWindowPos2dARB(...) callWithGLCheck(glWindowPos2dARB, __VA_ARGS__)
#define _glWindowPos2dv(...) callWithGLCheck(glWindowPos2dv, __VA_ARGS__)
#define _glWindowPos2dvARB(...) callWithGLCheck(glWindowPos2dvARB, __VA_ARGS__)
#define _glWindowPos2f(...) callWithGLCheck(glWindowPos2f, __VA_ARGS__)
#define _glWindowPos2fARB(...) callWithGLCheck(glWindowPos2fARB, __VA_ARGS__)
#define _glWindowPos2fv(...) callWithGLCheck(glWindowPos2fv, __VA_ARGS__)
#define _glWindowPos2fvARB(...) callWithGLCheck(glWindowPos2fvARB, __VA_ARGS__)
#define _glWindowPos2i(...) callWithGLCheck(glWindowPos2i, __VA_ARGS__)
#define _glWindowPos2iARB(...) callWithGLCheck(glWindowPos2iARB, __VA_ARGS__)
#define _glWindowPos2iv(...) callWithGLCheck(glWindowPos2iv, __VA_ARGS__)
#define _glWindowPos2ivARB(...) callWithGLCheck(glWindowPos2ivARB, __VA_ARGS__)
#define _glWindowPos2s(...) callWithGLCheck(glWindowPos2s, __VA_ARGS__)
#define _glWindowPos2sARB(...) callWithGLCheck(glWindowPos2sARB, __VA_ARGS__)
#define _glWindowPos2sv(...) callWithGLCheck(glWindowPos2sv, __VA_ARGS__)
#define _glWindowPos2svARB(...) callWithGLCheck(glWindowPos2svARB, __VA_ARGS__)
#define _glWindowPos3d(...) callWithGLCheck(glWindowPos3d, __VA_ARGS__)
#define _glWindowPos3dARB(...) callWithGLCheck(glWindowPos3dARB, __VA_ARGS__)
#define _glWindowPos3dv(...) callWithGLCheck(glWindowPos3dv, __VA_ARGS__)
#define _glWindowPos3dvARB(...) callWithGLCheck(glWindowPos3dvARB, __VA_ARGS__)
#define _glWindowPos3f(...) callWithGLCheck(glWindowPos3f, __VA_ARGS__)
#define _glWindowPos3fARB(...) callWithGLCheck(glWindowPos3fARB, __VA_ARGS__)
#define _glWindowPos3fv(...) callWithGLCheck(glWindowPos3fv, __VA_ARGS__)
#define _glWindowPos3fvARB(...) callWithGLCheck(glWindowPos3fvARB, __VA_ARGS__)
#define _glWindowPos3i(...) callWithGLCheck(glWindowPos3i, __VA_ARGS__)
#define _glWindowPos3iARB(...) callWithGLCheck(glWindowPos3iARB, __VA_ARGS__)
#define _glWindowPos3iv(...) callWithGLCheck(glWindowPos3iv, __VA_ARGS__)
#define _glWindowPos3ivARB(...) callWithGLCheck(glWindowPos3ivARB, __VA_ARGS__)
#define _glWindowPos3s(...) callWithGLCheck(glWindowPos3s, __VA_ARGS__)
#define _glWindowPos3sARB(...) callWithGLCheck(glWindowPos3sARB, __VA_ARGS__)
#define _glWindowPos3sv(...) callWithGLCheck(glWindowPos3sv, __VA_ARGS__)
#define _glWindowPos3svARB(...) callWithGLCheck(glWindowPos3svARB, __VA_ARGS__)
#define _glAccum(...) callWithGLCheck(glAccum, __VA_ARGS__)
#define _glAccumProcPtr(...) callWithGLCheck(glAccumProcPtr, __VA_ARGS__)
#define _glActiveTexture(...) callWithGLCheck(glActiveTexture, __VA_ARGS__)
#define _glActiveTextureProcPtr(...) \
    callWithGLCheck(glActiveTextureProcPtr, __VA_ARGS__)
#define _glAlphaFunc(...) callWithGLCheck(glAlphaFunc, __VA_ARGS__)
#define _glAlphaFuncProcPtr(...) \
    callWithGLCheck(glAlphaFuncProcPtr, __VA_ARGS__)
#define _glAreTexturesResident(...) \
    callWithGLCheck(glAreTexturesResident, __VA_ARGS__)
#define _glAreTexturesResidentProcPtr(...) \
    callWithGLCheck(glAreTexturesResidentProcPtr, __VA_ARGS__)
#define _glArrayElement(...) callWithGLCheck(glArrayElement, __VA_ARGS__)
#define _glArrayElementProcPtr(...) \
    callWithGLCheck(glArrayElementProcPtr, __VA_ARGS__)
#define _glAttachShader(...) callWithGLCheck(glAttachShader, __VA_ARGS__)
#define _glAttachShaderProcPtr(...) \
    callWithGLCheck(glAttachShaderProcPtr, __VA_ARGS__)
#define _glBegin(...) callWithGLCheck(glBegin, __VA_ARGS__)
#define _glBeginProcPtr(...) callWithGLCheck(glBeginProcPtr, __VA_ARGS__)
#define _glBeginQuery(...) callWithGLCheck(glBeginQuery, __VA_ARGS__)
#define _glBeginQueryProcPtr(...) \
    callWithGLCheck(glBeginQueryProcPtr, __VA_ARGS__)
#define _glBindAttribLocation(...) \
    callWithGLCheck(glBindAttribLocation, __VA_ARGS__)
#define _glBindAttribLocationProcPtr(...) \
    callWithGLCheck(glBindAttribLocationProcPtr, __VA_ARGS__)
#define _glBindBuffer(...) callWithGLCheck(glBindBuffer, __VA_ARGS__)
#define _glBindBufferProcPtr(...) \
    callWithGLCheck(glBindBufferProcPtr, __VA_ARGS__)
#define _glBindTexture(...) callWithGLCheck(glBindTexture, __VA_ARGS__)
#define _glBindTextureProcPtr(...) \
    callWithGLCheck(glBindTextureProcPtr, __VA_ARGS__)
#define _glBitmap(...) callWithGLCheck(glBitmap, __VA_ARGS__)
#define _glBitmapProcPtr(...) callWithGLCheck(glBitmapProcPtr, __VA_ARGS__)
#define _glBlendColor(...) callWithGLCheck(glBlendColor, __VA_ARGS__)
#define _glBlendColorProcPtr(...) \
    callWithGLCheck(glBlendColorProcPtr, __VA_ARGS__)
#define _glBlendEquation(...) callWithGLCheck(glBlendEquation, __VA_ARGS__)
#define _glBlendEquationProcPtr(...) \
    callWithGLCheck(glBlendEquationProcPtr, __VA_ARGS__)
#define _glBlendEquationSeparate(...) \
    callWithGLCheck(glBlendEquationSeparate, __VA_ARGS__)
#define _glBlendEquationSeparateProcPtr(...) \
    callWithGLCheck(glBlendEquationSeparateProcPtr, __VA_ARGS__)
#define _glBlendFunc(...) callWithGLCheck(glBlendFunc, __VA_ARGS__)
#define _glBlendFuncProcPtr(...) \
    callWithGLCheck(glBlendFuncProcPtr, __VA_ARGS__)
#define _glBlendFuncSeparate(...) \
    callWithGLCheck(glBlendFuncSeparate, __VA_ARGS__)
#define _glBlendFuncSeparateProcPtr(...) \
    callWithGLCheck(glBlendFuncSeparateProcPtr, __VA_ARGS__)
#define _glBufferData(...) callWithGLCheck(glBufferData, __VA_ARGS__)
#define _glBufferDataProcPtr(...) \
    callWithGLCheck(glBufferDataProcPtr, __VA_ARGS__)
#define _glBufferSubData(...) callWithGLCheck(glBufferSubData, __VA_ARGS__)
#define _glBufferSubDataProcPtr(...) \
    callWithGLCheck(glBufferSubDataProcPtr, __VA_ARGS__)
#define _glCallList(...) callWithGLCheck(glCallList, __VA_ARGS__)
#define _glCallListProcPtr(...) callWithGLCheck(glCallListProcPtr, __VA_ARGS__)
#define _glCallLists(...) callWithGLCheck(glCallLists, __VA_ARGS__)
#define _glCallListsProcPtr(...) \
    callWithGLCheck(glCallListsProcPtr, __VA_ARGS__)
#define _glClear(...) callWithGLCheck(glClear, __VA_ARGS__)
#define _glClearAccum(...) callWithGLCheck(glClearAccum, __VA_ARGS__)
#define _glClearAccumProcPtr(...) \
    callWithGLCheck(glClearAccumProcPtr, __VA_ARGS__)
#define _glClearColor(...) callWithGLCheck(glClearColor, __VA_ARGS__)
#define _glClearColorProcPtr(...) \
    callWithGLCheck(glClearColorProcPtr, __VA_ARGS__)
#define _glClearDepth(...) callWithGLCheck(glClearDepth, __VA_ARGS__)
#define _glClearDepthProcPtr(...) \
    callWithGLCheck(glClearDepthProcPtr, __VA_ARGS__)
#define _glClearIndex(...) callWithGLCheck(glClearIndex, __VA_ARGS__)
#define _glClearIndexProcPtr(...) \
    callWithGLCheck(glClearIndexProcPtr, __VA_ARGS__)
#define _glClearProcPtr(...) callWithGLCheck(glClearProcPtr, __VA_ARGS__)
#define _glClearStencil(...) callWithGLCheck(glClearStencil, __VA_ARGS__)
#define _glClearStencilProcPtr(...) \
    callWithGLCheck(glClearStencilProcPtr, __VA_ARGS__)
#define _glClientActiveTexture(...) \
    callWithGLCheck(glClientActiveTexture, __VA_ARGS__)
#define _glClientActiveTextureProcPtr(...) \
    callWithGLCheck(glClientActiveTextureProcPtr, __VA_ARGS__)
#define _glClipPlane(...) callWithGLCheck(glClipPlane, __VA_ARGS__)
#define _glClipPlaneProcPtr(...) \
    callWithGLCheck(glClipPlaneProcPtr, __VA_ARGS__)
#define _glColor3b(...) callWithGLCheck(glColor3b, __VA_ARGS__)
#define _glColor3bProcPtr(...) callWithGLCheck(glColor3bProcPtr, __VA_ARGS__)
#define _glColor3bv(...) callWithGLCheck(glColor3bv, __VA_ARGS__)
#define _glColor3bvProcPtr(...) callWithGLCheck(glColor3bvProcPtr, __VA_ARGS__)
#define _glColor3d(...) callWithGLCheck(glColor3d, __VA_ARGS__)
#define _glColor3dProcPtr(...) callWithGLCheck(glColor3dProcPtr, __VA_ARGS__)
#define _glColor3dv(...) callWithGLCheck(glColor3dv, __VA_ARGS__)
#define _glColor3dvProcPtr(...) callWithGLCheck(glColor3dvProcPtr, __VA_ARGS__)
#define _glColor3f(...) callWithGLCheck(glColor3f, __VA_ARGS__)
#define _glColor3fProcPtr(...) callWithGLCheck(glColor3fProcPtr, __VA_ARGS__)
#define _glColor3fv(...) callWithGLCheck(glColor3fv, __VA_ARGS__)
#define _glColor3fvProcPtr(...) callWithGLCheck(glColor3fvProcPtr, __VA_ARGS__)
#define _glColor3i(...) callWithGLCheck(glColor3i, __VA_ARGS__)
#define _glColor3iProcPtr(...) callWithGLCheck(glColor3iProcPtr, __VA_ARGS__)
#define _glColor3iv(...) callWithGLCheck(glColor3iv, __VA_ARGS__)
#define _glColor3ivProcPtr(...) callWithGLCheck(glColor3ivProcPtr, __VA_ARGS__)
#define _glColor3s(...) callWithGLCheck(glColor3s, __VA_ARGS__)
#define _glColor3sProcPtr(...) callWithGLCheck(glColor3sProcPtr, __VA_ARGS__)
#define _glColor3sv(...) callWithGLCheck(glColor3sv, __VA_ARGS__)
#define _glColor3svProcPtr(...) callWithGLCheck(glColor3svProcPtr, __VA_ARGS__)
#define _glColor3ub(...) callWithGLCheck(glColor3ub, __VA_ARGS__)
#define _glColor3ubProcPtr(...) callWithGLCheck(glColor3ubProcPtr, __VA_ARGS__)
#define _glColor3ubv(...) callWithGLCheck(glColor3ubv, __VA_ARGS__)
#define _glColor3ubvProcPtr(...) \
    callWithGLCheck(glColor3ubvProcPtr, __VA_ARGS__)
#define _glColor3ui(...) callWithGLCheck(glColor3ui, __VA_ARGS__)
#define _glColor3uiProcPtr(...) callWithGLCheck(glColor3uiProcPtr, __VA_ARGS__)
#define _glColor3uiv(...) callWithGLCheck(glColor3uiv, __VA_ARGS__)
#define _glColor3uivProcPtr(...) \
    callWithGLCheck(glColor3uivProcPtr, __VA_ARGS__)
#define _glColor3us(...) callWithGLCheck(glColor3us, __VA_ARGS__)
#define _glColor3usProcPtr(...) callWithGLCheck(glColor3usProcPtr, __VA_ARGS__)
#define _glColor3usv(...) callWithGLCheck(glColor3usv, __VA_ARGS__)
#define _glColor3usvProcPtr(...) \
    callWithGLCheck(glColor3usvProcPtr, __VA_ARGS__)
#define _glColor4b(...) callWithGLCheck(glColor4b, __VA_ARGS__)
#define _glColor4bProcPtr(...) callWithGLCheck(glColor4bProcPtr, __VA_ARGS__)
#define _glColor4bv(...) callWithGLCheck(glColor4bv, __VA_ARGS__)
#define _glColor4bvProcPtr(...) callWithGLCheck(glColor4bvProcPtr, __VA_ARGS__)
#define _glColor4d(...) callWithGLCheck(glColor4d, __VA_ARGS__)
#define _glColor4dProcPtr(...) callWithGLCheck(glColor4dProcPtr, __VA_ARGS__)
#define _glColor4dv(...) callWithGLCheck(glColor4dv, __VA_ARGS__)
#define _glColor4dvProcPtr(...) callWithGLCheck(glColor4dvProcPtr, __VA_ARGS__)
#define _glColor4f(...) callWithGLCheck(glColor4f, __VA_ARGS__)
#define _glColor4fProcPtr(...) callWithGLCheck(glColor4fProcPtr, __VA_ARGS__)
#define _glColor4fv(...) callWithGLCheck(glColor4fv, __VA_ARGS__)
#define _glColor4fvProcPtr(...) callWithGLCheck(glColor4fvProcPtr, __VA_ARGS__)
#define _glColor4i(...) callWithGLCheck(glColor4i, __VA_ARGS__)
#define _glColor4iProcPtr(...) callWithGLCheck(glColor4iProcPtr, __VA_ARGS__)
#define _glColor4iv(...) callWithGLCheck(glColor4iv, __VA_ARGS__)
#define _glColor4ivProcPtr(...) callWithGLCheck(glColor4ivProcPtr, __VA_ARGS__)
#define _glColor4s(...) callWithGLCheck(glColor4s, __VA_ARGS__)
#define _glColor4sProcPtr(...) callWithGLCheck(glColor4sProcPtr, __VA_ARGS__)
#define _glColor4sv(...) callWithGLCheck(glColor4sv, __VA_ARGS__)
#define _glColor4svProcPtr(...) callWithGLCheck(glColor4svProcPtr, __VA_ARGS__)
#define _glColor4ub(...) callWithGLCheck(glColor4ub, __VA_ARGS__)
#define _glColor4ubProcPtr(...) callWithGLCheck(glColor4ubProcPtr, __VA_ARGS__)
#define _glColor4ubv(...) callWithGLCheck(glColor4ubv, __VA_ARGS__)
#define _glColor4ubvProcPtr(...) \
    callWithGLCheck(glColor4ubvProcPtr, __VA_ARGS__)
#define _glColor4ui(...) callWithGLCheck(glColor4ui, __VA_ARGS__)
#define _glColor4uiProcPtr(...) callWithGLCheck(glColor4uiProcPtr, __VA_ARGS__)
#define _glColor4uiv(...) callWithGLCheck(glColor4uiv, __VA_ARGS__)
#define _glColor4uivProcPtr(...) \
    callWithGLCheck(glColor4uivProcPtr, __VA_ARGS__)
#define _glColor4us(...) callWithGLCheck(glColor4us, __VA_ARGS__)
#define _glColor4usProcPtr(...) callWithGLCheck(glColor4usProcPtr, __VA_ARGS__)
#define _glColor4usv(...) callWithGLCheck(glColor4usv, __VA_ARGS__)
#define _glColor4usvProcPtr(...) \
    callWithGLCheck(glColor4usvProcPtr, __VA_ARGS__)
#define _glColorMask(...) callWithGLCheck(glColorMask, __VA_ARGS__)
#define _glColorMaskProcPtr(...) \
    callWithGLCheck(glColorMaskProcPtr, __VA_ARGS__)
#define _glColorMaterial(...) callWithGLCheck(glColorMaterial, __VA_ARGS__)
#define _glColorMaterialProcPtr(...) \
    callWithGLCheck(glColorMaterialProcPtr, __VA_ARGS__)
#define _glColorPointer(...) callWithGLCheck(glColorPointer, __VA_ARGS__)
#define _glColorPointerProcPtr(...) \
    callWithGLCheck(glColorPointerProcPtr, __VA_ARGS__)
#define _glColorSubTable(...) callWithGLCheck(glColorSubTable, __VA_ARGS__)
#define _glColorSubTableProcPtr(...) \
    callWithGLCheck(glColorSubTableProcPtr, __VA_ARGS__)
#define _glColorTable(...) callWithGLCheck(glColorTable, __VA_ARGS__)
#define _glColorTableParameterfv(...) \
    callWithGLCheck(glColorTableParameterfv, __VA_ARGS__)
#define _glColorTableParameterfvProcPtr(...) \
    callWithGLCheck(glColorTableParameterfvProcPtr, __VA_ARGS__)
#define _glColorTableParameteriv(...) \
    callWithGLCheck(glColorTableParameteriv, __VA_ARGS__)
#define _glColorTableParameterivProcPtr(...) \
    callWithGLCheck(glColorTableParameterivProcPtr, __VA_ARGS__)
#define _glColorTableProcPtr(...) \
    callWithGLCheck(glColorTableProcPtr, __VA_ARGS__)
#define _glCompileShader(...) callWithGLCheck(glCompileShader, __VA_ARGS__)
#define _glCompileShaderProcPtr(...) \
    callWithGLCheck(glCompileShaderProcPtr, __VA_ARGS__)
#define _glCompressedTexImage1D(...) \
    callWithGLCheck(glCompressedTexImage1D, __VA_ARGS__)
#define _glCompressedTexImage1DProcPtr(...) \
    callWithGLCheck(glCompressedTexImage1DProcPtr, __VA_ARGS__)
#define _glCompressedTexImage2D(...) \
    callWithGLCheck(glCompressedTexImage2D, __VA_ARGS__)
#define _glCompressedTexImage2DProcPtr(...) \
    callWithGLCheck(glCompressedTexImage2DProcPtr, __VA_ARGS__)
#define _glCompressedTexImage3D(...) \
    callWithGLCheck(glCompressedTexImage3D, __VA_ARGS__)
#define _glCompressedTexImage3DProcPtr(...) \
    callWithGLCheck(glCompressedTexImage3DProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage1D(...) \
    callWithGLCheck(glCompressedTexSubImage1D, __VA_ARGS__)
#define _glCompressedTexSubImage1DProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage1DProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage2D(...) \
    callWithGLCheck(glCompressedTexSubImage2D, __VA_ARGS__)
#define _glCompressedTexSubImage2DProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage2DProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage3D(...) \
    callWithGLCheck(glCompressedTexSubImage3D, __VA_ARGS__)
#define _glCompressedTexSubImage3DProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage3DProcPtr, __VA_ARGS__)
#define _glConvolutionFilter1D(...) \
    callWithGLCheck(glConvolutionFilter1D, __VA_ARGS__)
#define _glConvolutionFilter1DProcPtr(...) \
    callWithGLCheck(glConvolutionFilter1DProcPtr, __VA_ARGS__)
#define _glConvolutionFilter2D(...) \
    callWithGLCheck(glConvolutionFilter2D, __VA_ARGS__)
#define _glConvolutionFilter2DProcPtr(...) \
    callWithGLCheck(glConvolutionFilter2DProcPtr, __VA_ARGS__)
#define _glConvolutionParameterf(...) \
    callWithGLCheck(glConvolutionParameterf, __VA_ARGS__)
#define _glConvolutionParameterfProcPtr(...) \
    callWithGLCheck(glConvolutionParameterfProcPtr, __VA_ARGS__)
#define _glConvolutionParameterfv(...) \
    callWithGLCheck(glConvolutionParameterfv, __VA_ARGS__)
#define _glConvolutionParameterfvProcPtr(...) \
    callWithGLCheck(glConvolutionParameterfvProcPtr, __VA_ARGS__)
#define _glConvolutionParameteri(...) \
    callWithGLCheck(glConvolutionParameteri, __VA_ARGS__)
#define _glConvolutionParameteriProcPtr(...) \
    callWithGLCheck(glConvolutionParameteriProcPtr, __VA_ARGS__)
#define _glConvolutionParameteriv(...) \
    callWithGLCheck(glConvolutionParameteriv, __VA_ARGS__)
#define _glConvolutionParameterivProcPtr(...) \
    callWithGLCheck(glConvolutionParameterivProcPtr, __VA_ARGS__)
#define _glCopyColorSubTable(...) \
    callWithGLCheck(glCopyColorSubTable, __VA_ARGS__)
#define _glCopyColorSubTableProcPtr(...) \
    callWithGLCheck(glCopyColorSubTableProcPtr, __VA_ARGS__)
#define _glCopyColorTable(...) callWithGLCheck(glCopyColorTable, __VA_ARGS__)
#define _glCopyColorTableProcPtr(...) \
    callWithGLCheck(glCopyColorTableProcPtr, __VA_ARGS__)
#define _glCopyConvolutionFilter1D(...) \
    callWithGLCheck(glCopyConvolutionFilter1D, __VA_ARGS__)
#define _glCopyConvolutionFilter1DProcPtr(...) \
    callWithGLCheck(glCopyConvolutionFilter1DProcPtr, __VA_ARGS__)
#define _glCopyConvolutionFilter2D(...) \
    callWithGLCheck(glCopyConvolutionFilter2D, __VA_ARGS__)
#define _glCopyConvolutionFilter2DProcPtr(...) \
    callWithGLCheck(glCopyConvolutionFilter2DProcPtr, __VA_ARGS__)
#define _glCopyPixels(...) callWithGLCheck(glCopyPixels, __VA_ARGS__)
#define _glCopyPixelsProcPtr(...) \
    callWithGLCheck(glCopyPixelsProcPtr, __VA_ARGS__)
#define _glCopyTexImage1D(...) callWithGLCheck(glCopyTexImage1D, __VA_ARGS__)
#define _glCopyTexImage1DProcPtr(...) \
    callWithGLCheck(glCopyTexImage1DProcPtr, __VA_ARGS__)
#define _glCopyTexImage2D(...) callWithGLCheck(glCopyTexImage2D, __VA_ARGS__)
#define _glCopyTexImage2DProcPtr(...) \
    callWithGLCheck(glCopyTexImage2DProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage1D(...) \
    callWithGLCheck(glCopyTexSubImage1D, __VA_ARGS__)
#define _glCopyTexSubImage1DProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage1DProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage2D(...) \
    callWithGLCheck(glCopyTexSubImage2D, __VA_ARGS__)
#define _glCopyTexSubImage2DProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage2DProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage3D(...) \
    callWithGLCheck(glCopyTexSubImage3D, __VA_ARGS__)
#define _glCopyTexSubImage3DProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage3DProcPtr, __VA_ARGS__)
#define _glCreateProgram(...) callWithGLCheck(glCreateProgram, __VA_ARGS__)
#define _glCreateProgramProcPtr(...) \
    callWithGLCheck(glCreateProgramProcPtr, __VA_ARGS__)
#define _glCreateShader(...) callWithGLCheck(glCreateShader, __VA_ARGS__)
#define _glCreateShaderProcPtr(...) \
    callWithGLCheck(glCreateShaderProcPtr, __VA_ARGS__)
#define _glCullFace(...) callWithGLCheck(glCullFace, __VA_ARGS__)
#define _glCullFaceProcPtr(...) callWithGLCheck(glCullFaceProcPtr, __VA_ARGS__)
#define _glDeleteBuffers(...) callWithGLCheck(glDeleteBuffers, __VA_ARGS__)
#define _glDeleteBuffersProcPtr(...) \
    callWithGLCheck(glDeleteBuffersProcPtr, __VA_ARGS__)
#define _glDeleteLists(...) callWithGLCheck(glDeleteLists, __VA_ARGS__)
#define _glDeleteListsProcPtr(...) \
    callWithGLCheck(glDeleteListsProcPtr, __VA_ARGS__)
#define _glDeleteProgram(...) callWithGLCheck(glDeleteProgram, __VA_ARGS__)
#define _glDeleteProgramProcPtr(...) \
    callWithGLCheck(glDeleteProgramProcPtr, __VA_ARGS__)
#define _glDeleteQueries(...) callWithGLCheck(glDeleteQueries, __VA_ARGS__)
#define _glDeleteQueriesProcPtr(...) \
    callWithGLCheck(glDeleteQueriesProcPtr, __VA_ARGS__)
#define _glDeleteShader(...) callWithGLCheck(glDeleteShader, __VA_ARGS__)
#define _glDeleteShaderProcPtr(...) \
    callWithGLCheck(glDeleteShaderProcPtr, __VA_ARGS__)
#define _glDeleteTextures(...) callWithGLCheck(glDeleteTextures, __VA_ARGS__)
#define _glDeleteTexturesProcPtr(...) \
    callWithGLCheck(glDeleteTexturesProcPtr, __VA_ARGS__)
#define _glDepthFunc(...) callWithGLCheck(glDepthFunc, __VA_ARGS__)
#define _glDepthFuncProcPtr(...) \
    callWithGLCheck(glDepthFuncProcPtr, __VA_ARGS__)
#define _glDepthMask(...) callWithGLCheck(glDepthMask, __VA_ARGS__)
#define _glDepthMaskProcPtr(...) \
    callWithGLCheck(glDepthMaskProcPtr, __VA_ARGS__)
#define _glDepthRange(...) callWithGLCheck(glDepthRange, __VA_ARGS__)
#define _glDepthRangeProcPtr(...) \
    callWithGLCheck(glDepthRangeProcPtr, __VA_ARGS__)
#define _glDetachShader(...) callWithGLCheck(glDetachShader, __VA_ARGS__)
#define _glDetachShaderProcPtr(...) \
    callWithGLCheck(glDetachShaderProcPtr, __VA_ARGS__)
#define _glDisable(...) callWithGLCheck(glDisable, __VA_ARGS__)
#define _glDisableClientState(...) \
    callWithGLCheck(glDisableClientState, __VA_ARGS__)
#define _glDisableClientStateProcPtr(...) \
    callWithGLCheck(glDisableClientStateProcPtr, __VA_ARGS__)
#define _glDisableProcPtr(...) callWithGLCheck(glDisableProcPtr, __VA_ARGS__)
#define _glDisableVertexAttribArray(...) \
    callWithGLCheck(glDisableVertexAttribArray, __VA_ARGS__)
#define _glDisableVertexAttribArrayProcPtr(...) \
    callWithGLCheck(glDisableVertexAttribArrayProcPtr, __VA_ARGS__)
#define _glDrawArrays(...) callWithGLCheck(glDrawArrays, __VA_ARGS__)
#define _glDrawArraysProcPtr(...) \
    callWithGLCheck(glDrawArraysProcPtr, __VA_ARGS__)
#define _glDrawBuffer(...) callWithGLCheck(glDrawBuffer, __VA_ARGS__)
#define _glDrawBufferProcPtr(...) \
    callWithGLCheck(glDrawBufferProcPtr, __VA_ARGS__)
#define _glDrawBuffers(...) callWithGLCheck(glDrawBuffers, __VA_ARGS__)
#define _glDrawBuffersProcPtr(...) \
    callWithGLCheck(glDrawBuffersProcPtr, __VA_ARGS__)
#define _glDrawElements(...) callWithGLCheck(glDrawElements, __VA_ARGS__)
#define _glDrawElementsProcPtr(...) \
    callWithGLCheck(glDrawElementsProcPtr, __VA_ARGS__)
#define _glDrawPixels(...) callWithGLCheck(glDrawPixels, __VA_ARGS__)
#define _glDrawPixelsProcPtr(...) \
    callWithGLCheck(glDrawPixelsProcPtr, __VA_ARGS__)
#define _glDrawRangeElements(...) \
    callWithGLCheck(glDrawRangeElements, __VA_ARGS__)
#define _glDrawRangeElementsProcPtr(...) \
    callWithGLCheck(glDrawRangeElementsProcPtr, __VA_ARGS__)
#define _glEdgeFlag(...) callWithGLCheck(glEdgeFlag, __VA_ARGS__)
#define _glEdgeFlagPointer(...) callWithGLCheck(glEdgeFlagPointer, __VA_ARGS__)
#define _glEdgeFlagPointerProcPtr(...) \
    callWithGLCheck(glEdgeFlagPointerProcPtr, __VA_ARGS__)
#define _glEdgeFlagProcPtr(...) callWithGLCheck(glEdgeFlagProcPtr, __VA_ARGS__)
#define _glEdgeFlagv(...) callWithGLCheck(glEdgeFlagv, __VA_ARGS__)
#define _glEdgeFlagvProcPtr(...) \
    callWithGLCheck(glEdgeFlagvProcPtr, __VA_ARGS__)
#define _glEnable(...) callWithGLCheck(glEnable, __VA_ARGS__)
#define _glEnableClientState(...) \
    callWithGLCheck(glEnableClientState, __VA_ARGS__)
#define _glEnableClientStateProcPtr(...) \
    callWithGLCheck(glEnableClientStateProcPtr, __VA_ARGS__)
#define _glEnableProcPtr(...) callWithGLCheck(glEnableProcPtr, __VA_ARGS__)
#define _glEnableVertexAttribArray(...) \
    callWithGLCheck(glEnableVertexAttribArray, __VA_ARGS__)
#define _glEnableVertexAttribArrayProcPtr(...) \
    callWithGLCheck(glEnableVertexAttribArrayProcPtr, __VA_ARGS__)
#define _glEnd(...) callWithGLCheck(glEnd, __VA_ARGS__)
#define _glEndList(...) callWithGLCheck(glEndList, __VA_ARGS__)
#define _glEndListProcPtr(...) callWithGLCheck(glEndListProcPtr, __VA_ARGS__)
#define _glEndProcPtr(...) callWithGLCheck(glEndProcPtr, __VA_ARGS__)
#define _glEndQuery(...) callWithGLCheck(glEndQuery, __VA_ARGS__)
#define _glEndQueryProcPtr(...) callWithGLCheck(glEndQueryProcPtr, __VA_ARGS__)
#define _glEvalCoord1d(...) callWithGLCheck(glEvalCoord1d, __VA_ARGS__)
#define _glEvalCoord1dProcPtr(...) \
    callWithGLCheck(glEvalCoord1dProcPtr, __VA_ARGS__)
#define _glEvalCoord1dv(...) callWithGLCheck(glEvalCoord1dv, __VA_ARGS__)
#define _glEvalCoord1dvProcPtr(...) \
    callWithGLCheck(glEvalCoord1dvProcPtr, __VA_ARGS__)
#define _glEvalCoord1f(...) callWithGLCheck(glEvalCoord1f, __VA_ARGS__)
#define _glEvalCoord1fProcPtr(...) \
    callWithGLCheck(glEvalCoord1fProcPtr, __VA_ARGS__)
#define _glEvalCoord1fv(...) callWithGLCheck(glEvalCoord1fv, __VA_ARGS__)
#define _glEvalCoord1fvProcPtr(...) \
    callWithGLCheck(glEvalCoord1fvProcPtr, __VA_ARGS__)
#define _glEvalCoord2d(...) callWithGLCheck(glEvalCoord2d, __VA_ARGS__)
#define _glEvalCoord2dProcPtr(...) \
    callWithGLCheck(glEvalCoord2dProcPtr, __VA_ARGS__)
#define _glEvalCoord2dv(...) callWithGLCheck(glEvalCoord2dv, __VA_ARGS__)
#define _glEvalCoord2dvProcPtr(...) \
    callWithGLCheck(glEvalCoord2dvProcPtr, __VA_ARGS__)
#define _glEvalCoord2f(...) callWithGLCheck(glEvalCoord2f, __VA_ARGS__)
#define _glEvalCoord2fProcPtr(...) \
    callWithGLCheck(glEvalCoord2fProcPtr, __VA_ARGS__)
#define _glEvalCoord2fv(...) callWithGLCheck(glEvalCoord2fv, __VA_ARGS__)
#define _glEvalCoord2fvProcPtr(...) \
    callWithGLCheck(glEvalCoord2fvProcPtr, __VA_ARGS__)
#define _glEvalMesh1(...) callWithGLCheck(glEvalMesh1, __VA_ARGS__)
#define _glEvalMesh1ProcPtr(...) \
    callWithGLCheck(glEvalMesh1ProcPtr, __VA_ARGS__)
#define _glEvalMesh2(...) callWithGLCheck(glEvalMesh2, __VA_ARGS__)
#define _glEvalMesh2ProcPtr(...) \
    callWithGLCheck(glEvalMesh2ProcPtr, __VA_ARGS__)
#define _glEvalPoint1(...) callWithGLCheck(glEvalPoint1, __VA_ARGS__)
#define _glEvalPoint1ProcPtr(...) \
    callWithGLCheck(glEvalPoint1ProcPtr, __VA_ARGS__)
#define _glEvalPoint2(...) callWithGLCheck(glEvalPoint2, __VA_ARGS__)
#define _glEvalPoint2ProcPtr(...) \
    callWithGLCheck(glEvalPoint2ProcPtr, __VA_ARGS__)
#define _glFeedbackBuffer(...) callWithGLCheck(glFeedbackBuffer, __VA_ARGS__)
#define _glFeedbackBufferProcPtr(...) \
    callWithGLCheck(glFeedbackBufferProcPtr, __VA_ARGS__)
#define _glFinish(...) callWithGLCheck(glFinish, __VA_ARGS__)
#define _glFinishProcPtr(...) callWithGLCheck(glFinishProcPtr, __VA_ARGS__)
#define _glFlush(...) callWithGLCheck(glFlush, __VA_ARGS__)
#define _glFlushProcPtr(...) callWithGLCheck(glFlushProcPtr, __VA_ARGS__)
#define _glFogCoordPointer(...) callWithGLCheck(glFogCoordPointer, __VA_ARGS__)
#define _glFogCoordPointerProcPtr(...) \
    callWithGLCheck(glFogCoordPointerProcPtr, __VA_ARGS__)
#define _glFogCoordd(...) callWithGLCheck(glFogCoordd, __VA_ARGS__)
#define _glFogCoorddProcPtr(...) \
    callWithGLCheck(glFogCoorddProcPtr, __VA_ARGS__)
#define _glFogCoorddv(...) callWithGLCheck(glFogCoorddv, __VA_ARGS__)
#define _glFogCoorddvProcPtr(...) \
    callWithGLCheck(glFogCoorddvProcPtr, __VA_ARGS__)
#define _glFogCoordf(...) callWithGLCheck(glFogCoordf, __VA_ARGS__)
#define _glFogCoordfProcPtr(...) \
    callWithGLCheck(glFogCoordfProcPtr, __VA_ARGS__)
#define _glFogCoordfv(...) callWithGLCheck(glFogCoordfv, __VA_ARGS__)
#define _glFogCoordfvProcPtr(...) \
    callWithGLCheck(glFogCoordfvProcPtr, __VA_ARGS__)
#define _glFogf(...) callWithGLCheck(glFogf, __VA_ARGS__)
#define _glFogfProcPtr(...) callWithGLCheck(glFogfProcPtr, __VA_ARGS__)
#define _glFogfv(...) callWithGLCheck(glFogfv, __VA_ARGS__)
#define _glFogfvProcPtr(...) callWithGLCheck(glFogfvProcPtr, __VA_ARGS__)
#define _glFogi(...) callWithGLCheck(glFogi, __VA_ARGS__)
#define _glFogiProcPtr(...) callWithGLCheck(glFogiProcPtr, __VA_ARGS__)
#define _glFogiv(...) callWithGLCheck(glFogiv, __VA_ARGS__)
#define _glFogivProcPtr(...) callWithGLCheck(glFogivProcPtr, __VA_ARGS__)
#define _glFrontFace(...) callWithGLCheck(glFrontFace, __VA_ARGS__)
#define _glFrontFaceProcPtr(...) \
    callWithGLCheck(glFrontFaceProcPtr, __VA_ARGS__)
#define _glFrustum(...) callWithGLCheck(glFrustum, __VA_ARGS__)
#define _glFrustumProcPtr(...) callWithGLCheck(glFrustumProcPtr, __VA_ARGS__)
#define _glGenBuffers(...) callWithGLCheck(glGenBuffers, __VA_ARGS__)
#define _glGenBuffersProcPtr(...) \
    callWithGLCheck(glGenBuffersProcPtr, __VA_ARGS__)
#define _glGenLists(...) callWithGLCheck(glGenLists, __VA_ARGS__)
#define _glGenListsProcPtr(...) callWithGLCheck(glGenListsProcPtr, __VA_ARGS__)
#define _glGenQueries(...) callWithGLCheck(glGenQueries, __VA_ARGS__)
#define _glGenQueriesProcPtr(...) \
    callWithGLCheck(glGenQueriesProcPtr, __VA_ARGS__)
#define _glGenTextures(...) callWithGLCheck(glGenTextures, __VA_ARGS__)
#define _glGenTexturesProcPtr(...) \
    callWithGLCheck(glGenTexturesProcPtr, __VA_ARGS__)
#define _glGetActiveAttrib(...) callWithGLCheck(glGetActiveAttrib, __VA_ARGS__)
#define _glGetActiveAttribProcPtr(...) \
    callWithGLCheck(glGetActiveAttribProcPtr, __VA_ARGS__)
#define _glGetActiveUniform(...) \
    callWithGLCheck(glGetActiveUniform, __VA_ARGS__)
#define _glGetActiveUniformProcPtr(...) \
    callWithGLCheck(glGetActiveUniformProcPtr, __VA_ARGS__)
#define _glGetAttachedShaders(...) \
    callWithGLCheck(glGetAttachedShaders, __VA_ARGS__)
#define _glGetAttachedShadersProcPtr(...) \
    callWithGLCheck(glGetAttachedShadersProcPtr, __VA_ARGS__)
#define _glGetAttribLocation(...) \
    callWithGLCheck(glGetAttribLocation, __VA_ARGS__)
#define _glGetAttribLocationProcPtr(...) \
    callWithGLCheck(glGetAttribLocationProcPtr, __VA_ARGS__)
#define _glGetBooleanv(...) callWithGLCheck(glGetBooleanv, __VA_ARGS__)
#define _glGetBooleanvProcPtr(...) \
    callWithGLCheck(glGetBooleanvProcPtr, __VA_ARGS__)
#define _glGetBufferParameteriv(...) \
    callWithGLCheck(glGetBufferParameteriv, __VA_ARGS__)
#define _glGetBufferParameterivProcPtr(...) \
    callWithGLCheck(glGetBufferParameterivProcPtr, __VA_ARGS__)
#define _glGetBufferPointerv(...) \
    callWithGLCheck(glGetBufferPointerv, __VA_ARGS__)
#define _glGetBufferPointervProcPtr(...) \
    callWithGLCheck(glGetBufferPointervProcPtr, __VA_ARGS__)
#define _glGetBufferSubData(...) \
    callWithGLCheck(glGetBufferSubData, __VA_ARGS__)
#define _glGetBufferSubDataProcPtr(...) \
    callWithGLCheck(glGetBufferSubDataProcPtr, __VA_ARGS__)
#define _glGetClipPlane(...) callWithGLCheck(glGetClipPlane, __VA_ARGS__)
#define _glGetClipPlaneProcPtr(...) \
    callWithGLCheck(glGetClipPlaneProcPtr, __VA_ARGS__)
#define _glGetColorTable(...) callWithGLCheck(glGetColorTable, __VA_ARGS__)
#define _glGetColorTableParameterfv(...) \
    callWithGLCheck(glGetColorTableParameterfv, __VA_ARGS__)
#define _glGetColorTableParameterfvProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterfvProcPtr, __VA_ARGS__)
#define _glGetColorTableParameteriv(...) \
    callWithGLCheck(glGetColorTableParameteriv, __VA_ARGS__)
#define _glGetColorTableParameterivProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterivProcPtr, __VA_ARGS__)
#define _glGetColorTableProcPtr(...) \
    callWithGLCheck(glGetColorTableProcPtr, __VA_ARGS__)
#define _glGetCompressedTexImage(...) \
    callWithGLCheck(glGetCompressedTexImage, __VA_ARGS__)
#define _glGetCompressedTexImageProcPtr(...) \
    callWithGLCheck(glGetCompressedTexImageProcPtr, __VA_ARGS__)
#define _glGetConvolutionFilter(...) \
    callWithGLCheck(glGetConvolutionFilter, __VA_ARGS__)
#define _glGetConvolutionFilterProcPtr(...) \
    callWithGLCheck(glGetConvolutionFilterProcPtr, __VA_ARGS__)
#define _glGetConvolutionParameterfv(...) \
    callWithGLCheck(glGetConvolutionParameterfv, __VA_ARGS__)
#define _glGetConvolutionParameterfvProcPtr(...) \
    callWithGLCheck(glGetConvolutionParameterfvProcPtr, __VA_ARGS__)
#define _glGetConvolutionParameteriv(...) \
    callWithGLCheck(glGetConvolutionParameteriv, __VA_ARGS__)
#define _glGetConvolutionParameterivProcPtr(...) \
    callWithGLCheck(glGetConvolutionParameterivProcPtr, __VA_ARGS__)
#define _glGetDoublev(...) callWithGLCheck(glGetDoublev, __VA_ARGS__)
#define _glGetDoublevProcPtr(...) \
    callWithGLCheck(glGetDoublevProcPtr, __VA_ARGS__)
#define _glGetError(...) callWithGLCheck(glGetError, __VA_ARGS__)
#define _glGetErrorProcPtr(...) callWithGLCheck(glGetErrorProcPtr, __VA_ARGS__)
#define _glGetFloatv(...) callWithGLCheck(glGetFloatv, __VA_ARGS__)
#define _glGetFloatvProcPtr(...) \
    callWithGLCheck(glGetFloatvProcPtr, __VA_ARGS__)
#define _glGetHistogram(...) callWithGLCheck(glGetHistogram, __VA_ARGS__)
#define _glGetHistogramParameterfv(...) \
    callWithGLCheck(glGetHistogramParameterfv, __VA_ARGS__)
#define _glGetHistogramParameterfvProcPtr(...) \
    callWithGLCheck(glGetHistogramParameterfvProcPtr, __VA_ARGS__)
#define _glGetHistogramParameteriv(...) \
    callWithGLCheck(glGetHistogramParameteriv, __VA_ARGS__)
#define _glGetHistogramParameterivProcPtr(...) \
    callWithGLCheck(glGetHistogramParameterivProcPtr, __VA_ARGS__)
#define _glGetHistogramProcPtr(...) \
    callWithGLCheck(glGetHistogramProcPtr, __VA_ARGS__)
#define _glGetIntegerv(...) callWithGLCheck(glGetIntegerv, __VA_ARGS__)
#define _glGetIntegervProcPtr(...) \
    callWithGLCheck(glGetIntegervProcPtr, __VA_ARGS__)
#define _glGetLightfv(...) callWithGLCheck(glGetLightfv, __VA_ARGS__)
#define _glGetLightfvProcPtr(...) \
    callWithGLCheck(glGetLightfvProcPtr, __VA_ARGS__)
#define _glGetLightiv(...) callWithGLCheck(glGetLightiv, __VA_ARGS__)
#define _glGetLightivProcPtr(...) \
    callWithGLCheck(glGetLightivProcPtr, __VA_ARGS__)
#define _glGetMapdv(...) callWithGLCheck(glGetMapdv, __VA_ARGS__)
#define _glGetMapdvProcPtr(...) callWithGLCheck(glGetMapdvProcPtr, __VA_ARGS__)
#define _glGetMapfv(...) callWithGLCheck(glGetMapfv, __VA_ARGS__)
#define _glGetMapfvProcPtr(...) callWithGLCheck(glGetMapfvProcPtr, __VA_ARGS__)
#define _glGetMapiv(...) callWithGLCheck(glGetMapiv, __VA_ARGS__)
#define _glGetMapivProcPtr(...) callWithGLCheck(glGetMapivProcPtr, __VA_ARGS__)
#define _glGetMaterialfv(...) callWithGLCheck(glGetMaterialfv, __VA_ARGS__)
#define _glGetMaterialfvProcPtr(...) \
    callWithGLCheck(glGetMaterialfvProcPtr, __VA_ARGS__)
#define _glGetMaterialiv(...) callWithGLCheck(glGetMaterialiv, __VA_ARGS__)
#define _glGetMaterialivProcPtr(...) \
    callWithGLCheck(glGetMaterialivProcPtr, __VA_ARGS__)
#define _glGetMinmax(...) callWithGLCheck(glGetMinmax, __VA_ARGS__)
#define _glGetMinmaxParameterfv(...) \
    callWithGLCheck(glGetMinmaxParameterfv, __VA_ARGS__)
#define _glGetMinmaxParameterfvProcPtr(...) \
    callWithGLCheck(glGetMinmaxParameterfvProcPtr, __VA_ARGS__)
#define _glGetMinmaxParameteriv(...) \
    callWithGLCheck(glGetMinmaxParameteriv, __VA_ARGS__)
#define _glGetMinmaxParameterivProcPtr(...) \
    callWithGLCheck(glGetMinmaxParameterivProcPtr, __VA_ARGS__)
#define _glGetMinmaxProcPtr(...) \
    callWithGLCheck(glGetMinmaxProcPtr, __VA_ARGS__)
#define _glGetPixelMapfv(...) callWithGLCheck(glGetPixelMapfv, __VA_ARGS__)
#define _glGetPixelMapfvProcPtr(...) \
    callWithGLCheck(glGetPixelMapfvProcPtr, __VA_ARGS__)
#define _glGetPixelMapuiv(...) callWithGLCheck(glGetPixelMapuiv, __VA_ARGS__)
#define _glGetPixelMapuivProcPtr(...) \
    callWithGLCheck(glGetPixelMapuivProcPtr, __VA_ARGS__)
#define _glGetPixelMapusv(...) callWithGLCheck(glGetPixelMapusv, __VA_ARGS__)
#define _glGetPixelMapusvProcPtr(...) \
    callWithGLCheck(glGetPixelMapusvProcPtr, __VA_ARGS__)
#define _glGetPointerv(...) callWithGLCheck(glGetPointerv, __VA_ARGS__)
#define _glGetPointervProcPtr(...) \
    callWithGLCheck(glGetPointervProcPtr, __VA_ARGS__)
#define _glGetPolygonStipple(...) \
    callWithGLCheck(glGetPolygonStipple, __VA_ARGS__)
#define _glGetPolygonStippleProcPtr(...) \
    callWithGLCheck(glGetPolygonStippleProcPtr, __VA_ARGS__)
#define _glGetProgramInfoLog(...) \
    callWithGLCheck(glGetProgramInfoLog, __VA_ARGS__)
#define _glGetProgramInfoLogProcPtr(...) \
    callWithGLCheck(glGetProgramInfoLogProcPtr, __VA_ARGS__)
#define _glGetProgramiv(...) callWithGLCheck(glGetProgramiv, __VA_ARGS__)
#define _glGetProgramivProcPtr(...) \
    callWithGLCheck(glGetProgramivProcPtr, __VA_ARGS__)
#define _glGetQueryObjectiv(...) \
    callWithGLCheck(glGetQueryObjectiv, __VA_ARGS__)
#define _glGetQueryObjectivProcPtr(...) \
    callWithGLCheck(glGetQueryObjectivProcPtr, __VA_ARGS__)
#define _glGetQueryObjectuiv(...) \
    callWithGLCheck(glGetQueryObjectuiv, __VA_ARGS__)
#define _glGetQueryObjectuivProcPtr(...) \
    callWithGLCheck(glGetQueryObjectuivProcPtr, __VA_ARGS__)
#define _glGetQueryiv(...) callWithGLCheck(glGetQueryiv, __VA_ARGS__)
#define _glGetQueryivProcPtr(...) \
    callWithGLCheck(glGetQueryivProcPtr, __VA_ARGS__)
#define _glGetSeparableFilter(...) \
    callWithGLCheck(glGetSeparableFilter, __VA_ARGS__)
#define _glGetSeparableFilterProcPtr(...) \
    callWithGLCheck(glGetSeparableFilterProcPtr, __VA_ARGS__)
#define _glGetShaderInfoLog(...) \
    callWithGLCheck(glGetShaderInfoLog, __VA_ARGS__)
#define _glGetShaderInfoLogProcPtr(...) \
    callWithGLCheck(glGetShaderInfoLogProcPtr, __VA_ARGS__)
#define _glGetShaderSource(...) callWithGLCheck(glGetShaderSource, __VA_ARGS__)
#define _glGetShaderSourceProcPtr(...) \
    callWithGLCheck(glGetShaderSourceProcPtr, __VA_ARGS__)
#define _glGetShaderiv(...) callWithGLCheck(glGetShaderiv, __VA_ARGS__)
#define _glGetShaderivProcPtr(...) \
    callWithGLCheck(glGetShaderivProcPtr, __VA_ARGS__)
#define _glGetString(...) callWithGLCheck(glGetString, __VA_ARGS__)
#define _glGetStringProcPtr(...) \
    callWithGLCheck(glGetStringProcPtr, __VA_ARGS__)
#define _glGetTexEnvfv(...) callWithGLCheck(glGetTexEnvfv, __VA_ARGS__)
#define _glGetTexEnvfvProcPtr(...) \
    callWithGLCheck(glGetTexEnvfvProcPtr, __VA_ARGS__)
#define _glGetTexEnviv(...) callWithGLCheck(glGetTexEnviv, __VA_ARGS__)
#define _glGetTexEnvivProcPtr(...) \
    callWithGLCheck(glGetTexEnvivProcPtr, __VA_ARGS__)
#define _glGetTexGendv(...) callWithGLCheck(glGetTexGendv, __VA_ARGS__)
#define _glGetTexGendvProcPtr(...) \
    callWithGLCheck(glGetTexGendvProcPtr, __VA_ARGS__)
#define _glGetTexGenfv(...) callWithGLCheck(glGetTexGenfv, __VA_ARGS__)
#define _glGetTexGenfvProcPtr(...) \
    callWithGLCheck(glGetTexGenfvProcPtr, __VA_ARGS__)
#define _glGetTexGeniv(...) callWithGLCheck(glGetTexGeniv, __VA_ARGS__)
#define _glGetTexGenivProcPtr(...) \
    callWithGLCheck(glGetTexGenivProcPtr, __VA_ARGS__)
#define _glGetTexImage(...) callWithGLCheck(glGetTexImage, __VA_ARGS__)
#define _glGetTexImageProcPtr(...) \
    callWithGLCheck(glGetTexImageProcPtr, __VA_ARGS__)
#define _glGetTexLevelParameterfv(...) \
    callWithGLCheck(glGetTexLevelParameterfv, __VA_ARGS__)
#define _glGetTexLevelParameterfvProcPtr(...) \
    callWithGLCheck(glGetTexLevelParameterfvProcPtr, __VA_ARGS__)
#define _glGetTexLevelParameteriv(...) \
    callWithGLCheck(glGetTexLevelParameteriv, __VA_ARGS__)
#define _glGetTexLevelParameterivProcPtr(...) \
    callWithGLCheck(glGetTexLevelParameterivProcPtr, __VA_ARGS__)
#define _glGetTexParameterfv(...) \
    callWithGLCheck(glGetTexParameterfv, __VA_ARGS__)
#define _glGetTexParameterfvProcPtr(...) \
    callWithGLCheck(glGetTexParameterfvProcPtr, __VA_ARGS__)
#define _glGetTexParameteriv(...) \
    callWithGLCheck(glGetTexParameteriv, __VA_ARGS__)
#define _glGetTexParameterivProcPtr(...) \
    callWithGLCheck(glGetTexParameterivProcPtr, __VA_ARGS__)
#define _glGetUniformLocation(...) \
    callWithGLCheck(glGetUniformLocation, __VA_ARGS__)
#define _glGetUniformLocationProcPtr(...) \
    callWithGLCheck(glGetUniformLocationProcPtr, __VA_ARGS__)
#define _glGetUniformfv(...) callWithGLCheck(glGetUniformfv, __VA_ARGS__)
#define _glGetUniformfvProcPtr(...) \
    callWithGLCheck(glGetUniformfvProcPtr, __VA_ARGS__)
#define _glGetUniformiv(...) callWithGLCheck(glGetUniformiv, __VA_ARGS__)
#define _glGetUniformivProcPtr(...) \
    callWithGLCheck(glGetUniformivProcPtr, __VA_ARGS__)
#define _glGetVertexAttribPointerv(...) \
    callWithGLCheck(glGetVertexAttribPointerv, __VA_ARGS__)
#define _glGetVertexAttribPointervProcPtr(...) \
    callWithGLCheck(glGetVertexAttribPointervProcPtr, __VA_ARGS__)
#define _glGetVertexAttribdv(...) \
    callWithGLCheck(glGetVertexAttribdv, __VA_ARGS__)
#define _glGetVertexAttribdvProcPtr(...) \
    callWithGLCheck(glGetVertexAttribdvProcPtr, __VA_ARGS__)
#define _glGetVertexAttribfv(...) \
    callWithGLCheck(glGetVertexAttribfv, __VA_ARGS__)
#define _glGetVertexAttribfvProcPtr(...) \
    callWithGLCheck(glGetVertexAttribfvProcPtr, __VA_ARGS__)
#define _glGetVertexAttribiv(...) \
    callWithGLCheck(glGetVertexAttribiv, __VA_ARGS__)
#define _glGetVertexAttribivProcPtr(...) \
    callWithGLCheck(glGetVertexAttribivProcPtr, __VA_ARGS__)
#define _glHint(...) callWithGLCheck(glHint, __VA_ARGS__)
#define _glHintProcPtr(...) callWithGLCheck(glHintProcPtr, __VA_ARGS__)
#define _glHistogram(...) callWithGLCheck(glHistogram, __VA_ARGS__)
#define _glHistogramProcPtr(...) \
    callWithGLCheck(glHistogramProcPtr, __VA_ARGS__)
#define _glIndexMask(...) callWithGLCheck(glIndexMask, __VA_ARGS__)
#define _glIndexMaskProcPtr(...) \
    callWithGLCheck(glIndexMaskProcPtr, __VA_ARGS__)
#define _glIndexPointer(...) callWithGLCheck(glIndexPointer, __VA_ARGS__)
#define _glIndexPointerProcPtr(...) \
    callWithGLCheck(glIndexPointerProcPtr, __VA_ARGS__)
#define _glIndexd(...) callWithGLCheck(glIndexd, __VA_ARGS__)
#define _glIndexdProcPtr(...) callWithGLCheck(glIndexdProcPtr, __VA_ARGS__)
#define _glIndexdv(...) callWithGLCheck(glIndexdv, __VA_ARGS__)
#define _glIndexdvProcPtr(...) callWithGLCheck(glIndexdvProcPtr, __VA_ARGS__)
#define _glIndexf(...) callWithGLCheck(glIndexf, __VA_ARGS__)
#define _glIndexfProcPtr(...) callWithGLCheck(glIndexfProcPtr, __VA_ARGS__)
#define _glIndexfv(...) callWithGLCheck(glIndexfv, __VA_ARGS__)
#define _glIndexfvProcPtr(...) callWithGLCheck(glIndexfvProcPtr, __VA_ARGS__)
#define _glIndexi(...) callWithGLCheck(glIndexi, __VA_ARGS__)
#define _glIndexiProcPtr(...) callWithGLCheck(glIndexiProcPtr, __VA_ARGS__)
#define _glIndexiv(...) callWithGLCheck(glIndexiv, __VA_ARGS__)
#define _glIndexivProcPtr(...) callWithGLCheck(glIndexivProcPtr, __VA_ARGS__)
#define _glIndexs(...) callWithGLCheck(glIndexs, __VA_ARGS__)
#define _glIndexsProcPtr(...) callWithGLCheck(glIndexsProcPtr, __VA_ARGS__)
#define _glIndexsv(...) callWithGLCheck(glIndexsv, __VA_ARGS__)
#define _glIndexsvProcPtr(...) callWithGLCheck(glIndexsvProcPtr, __VA_ARGS__)
#define _glIndexub(...) callWithGLCheck(glIndexub, __VA_ARGS__)
#define _glIndexubProcPtr(...) callWithGLCheck(glIndexubProcPtr, __VA_ARGS__)
#define _glIndexubv(...) callWithGLCheck(glIndexubv, __VA_ARGS__)
#define _glIndexubvProcPtr(...) callWithGLCheck(glIndexubvProcPtr, __VA_ARGS__)
#define _glInitNames(...) callWithGLCheck(glInitNames, __VA_ARGS__)
#define _glInitNamesProcPtr(...) \
    callWithGLCheck(glInitNamesProcPtr, __VA_ARGS__)
#define _glInterleavedArrays(...) \
    callWithGLCheck(glInterleavedArrays, __VA_ARGS__)
#define _glInterleavedArraysProcPtr(...) \
    callWithGLCheck(glInterleavedArraysProcPtr, __VA_ARGS__)
#define _glIsBuffer(...) callWithGLCheck(glIsBuffer, __VA_ARGS__)
#define _glIsBufferProcPtr(...) callWithGLCheck(glIsBufferProcPtr, __VA_ARGS__)
#define _glIsEnabled(...) callWithGLCheck(glIsEnabled, __VA_ARGS__)
#define _glIsEnabledProcPtr(...) \
    callWithGLCheck(glIsEnabledProcPtr, __VA_ARGS__)
#define _glIsList(...) callWithGLCheck(glIsList, __VA_ARGS__)
#define _glIsListProcPtr(...) callWithGLCheck(glIsListProcPtr, __VA_ARGS__)
#define _glIsProgram(...) callWithGLCheck(glIsProgram, __VA_ARGS__)
#define _glIsProgramProcPtr(...) \
    callWithGLCheck(glIsProgramProcPtr, __VA_ARGS__)
#define _glIsQuery(...) callWithGLCheck(glIsQuery, __VA_ARGS__)
#define _glIsQueryProcPtr(...) callWithGLCheck(glIsQueryProcPtr, __VA_ARGS__)
#define _glIsShader(...) callWithGLCheck(glIsShader, __VA_ARGS__)
#define _glIsShaderProcPtr(...) callWithGLCheck(glIsShaderProcPtr, __VA_ARGS__)
#define _glIsTexture(...) callWithGLCheck(glIsTexture, __VA_ARGS__)
#define _glIsTextureProcPtr(...) \
    callWithGLCheck(glIsTextureProcPtr, __VA_ARGS__)
#define _glLightModelf(...) callWithGLCheck(glLightModelf, __VA_ARGS__)
#define _glLightModelfProcPtr(...) \
    callWithGLCheck(glLightModelfProcPtr, __VA_ARGS__)
#define _glLightModelfv(...) callWithGLCheck(glLightModelfv, __VA_ARGS__)
#define _glLightModelfvProcPtr(...) \
    callWithGLCheck(glLightModelfvProcPtr, __VA_ARGS__)
#define _glLightModeli(...) callWithGLCheck(glLightModeli, __VA_ARGS__)
#define _glLightModeliProcPtr(...) \
    callWithGLCheck(glLightModeliProcPtr, __VA_ARGS__)
#define _glLightModeliv(...) callWithGLCheck(glLightModeliv, __VA_ARGS__)
#define _glLightModelivProcPtr(...) \
    callWithGLCheck(glLightModelivProcPtr, __VA_ARGS__)
#define _glLightf(...) callWithGLCheck(glLightf, __VA_ARGS__)
#define _glLightfProcPtr(...) callWithGLCheck(glLightfProcPtr, __VA_ARGS__)
#define _glLightfv(...) callWithGLCheck(glLightfv, __VA_ARGS__)
#define _glLightfvProcPtr(...) callWithGLCheck(glLightfvProcPtr, __VA_ARGS__)
#define _glLighti(...) callWithGLCheck(glLighti, __VA_ARGS__)
#define _glLightiProcPtr(...) callWithGLCheck(glLightiProcPtr, __VA_ARGS__)
#define _glLightiv(...) callWithGLCheck(glLightiv, __VA_ARGS__)
#define _glLightivProcPtr(...) callWithGLCheck(glLightivProcPtr, __VA_ARGS__)
#define _glLineStipple(...) callWithGLCheck(glLineStipple, __VA_ARGS__)
#define _glLineStippleProcPtr(...) \
    callWithGLCheck(glLineStippleProcPtr, __VA_ARGS__)
#define _glLineWidth(...) callWithGLCheck(glLineWidth, __VA_ARGS__)
#define _glLineWidthProcPtr(...) \
    callWithGLCheck(glLineWidthProcPtr, __VA_ARGS__)
#define _glLinkProgram(...) callWithGLCheck(glLinkProgram, __VA_ARGS__)
#define _glLinkProgramProcPtr(...) \
    callWithGLCheck(glLinkProgramProcPtr, __VA_ARGS__)
#define _glListBase(...) callWithGLCheck(glListBase, __VA_ARGS__)
#define _glListBaseProcPtr(...) callWithGLCheck(glListBaseProcPtr, __VA_ARGS__)
#define _glLoadIdentity(...) callWithGLCheck(glLoadIdentity, __VA_ARGS__)
#define _glLoadIdentityProcPtr(...) \
    callWithGLCheck(glLoadIdentityProcPtr, __VA_ARGS__)
#define _glLoadMatrixd(...) callWithGLCheck(glLoadMatrixd, __VA_ARGS__)
#define _glLoadMatrixdProcPtr(...) \
    callWithGLCheck(glLoadMatrixdProcPtr, __VA_ARGS__)
#define _glLoadMatrixf(...) callWithGLCheck(glLoadMatrixf, __VA_ARGS__)
#define _glLoadMatrixfProcPtr(...) \
    callWithGLCheck(glLoadMatrixfProcPtr, __VA_ARGS__)
#define _glLoadName(...) callWithGLCheck(glLoadName, __VA_ARGS__)
#define _glLoadNameProcPtr(...) callWithGLCheck(glLoadNameProcPtr, __VA_ARGS__)
#define _glLoadTransposeMatrixd(...) \
    callWithGLCheck(glLoadTransposeMatrixd, __VA_ARGS__)
#define _glLoadTransposeMatrixdProcPtr(...) \
    callWithGLCheck(glLoadTransposeMatrixdProcPtr, __VA_ARGS__)
#define _glLoadTransposeMatrixf(...) \
    callWithGLCheck(glLoadTransposeMatrixf, __VA_ARGS__)
#define _glLoadTransposeMatrixfProcPtr(...) \
    callWithGLCheck(glLoadTransposeMatrixfProcPtr, __VA_ARGS__)
#define _glLogicOp(...) callWithGLCheck(glLogicOp, __VA_ARGS__)
#define _glLogicOpProcPtr(...) callWithGLCheck(glLogicOpProcPtr, __VA_ARGS__)
#define _glMap1d(...) callWithGLCheck(glMap1d, __VA_ARGS__)
#define _glMap1dProcPtr(...) callWithGLCheck(glMap1dProcPtr, __VA_ARGS__)
#define _glMap1f(...) callWithGLCheck(glMap1f, __VA_ARGS__)
#define _glMap1fProcPtr(...) callWithGLCheck(glMap1fProcPtr, __VA_ARGS__)
#define _glMap2d(...) callWithGLCheck(glMap2d, __VA_ARGS__)
#define _glMap2dProcPtr(...) callWithGLCheck(glMap2dProcPtr, __VA_ARGS__)
#define _glMap2f(...) callWithGLCheck(glMap2f, __VA_ARGS__)
#define _glMap2fProcPtr(...) callWithGLCheck(glMap2fProcPtr, __VA_ARGS__)
#define _glMapBuffer(...) callWithGLCheck(glMapBuffer, __VA_ARGS__)
#define _glMapBufferProcPtr(...) \
    callWithGLCheck(glMapBufferProcPtr, __VA_ARGS__)
#define _glMapGrid1d(...) callWithGLCheck(glMapGrid1d, __VA_ARGS__)
#define _glMapGrid1dProcPtr(...) \
    callWithGLCheck(glMapGrid1dProcPtr, __VA_ARGS__)
#define _glMapGrid1f(...) callWithGLCheck(glMapGrid1f, __VA_ARGS__)
#define _glMapGrid1fProcPtr(...) \
    callWithGLCheck(glMapGrid1fProcPtr, __VA_ARGS__)
#define _glMapGrid2d(...) callWithGLCheck(glMapGrid2d, __VA_ARGS__)
#define _glMapGrid2dProcPtr(...) \
    callWithGLCheck(glMapGrid2dProcPtr, __VA_ARGS__)
#define _glMapGrid2f(...) callWithGLCheck(glMapGrid2f, __VA_ARGS__)
#define _glMapGrid2fProcPtr(...) \
    callWithGLCheck(glMapGrid2fProcPtr, __VA_ARGS__)
#define _glMaterialf(...) callWithGLCheck(glMaterialf, __VA_ARGS__)
#define _glMaterialfProcPtr(...) \
    callWithGLCheck(glMaterialfProcPtr, __VA_ARGS__)
#define _glMaterialfv(...) callWithGLCheck(glMaterialfv, __VA_ARGS__)
#define _glMaterialfvProcPtr(...) \
    callWithGLCheck(glMaterialfvProcPtr, __VA_ARGS__)
#define _glMateriali(...) callWithGLCheck(glMateriali, __VA_ARGS__)
#define _glMaterialiProcPtr(...) \
    callWithGLCheck(glMaterialiProcPtr, __VA_ARGS__)
#define _glMaterialiv(...) callWithGLCheck(glMaterialiv, __VA_ARGS__)
#define _glMaterialivProcPtr(...) \
    callWithGLCheck(glMaterialivProcPtr, __VA_ARGS__)
#define _glMatrixMode(...) callWithGLCheck(glMatrixMode, __VA_ARGS__)
#define _glMatrixModeProcPtr(...) \
    callWithGLCheck(glMatrixModeProcPtr, __VA_ARGS__)
#define _glMinmax(...) callWithGLCheck(glMinmax, __VA_ARGS__)
#define _glMinmaxProcPtr(...) callWithGLCheck(glMinmaxProcPtr, __VA_ARGS__)
#define _glMultMatrixd(...) callWithGLCheck(glMultMatrixd, __VA_ARGS__)
#define _glMultMatrixdProcPtr(...) \
    callWithGLCheck(glMultMatrixdProcPtr, __VA_ARGS__)
#define _glMultMatrixf(...) callWithGLCheck(glMultMatrixf, __VA_ARGS__)
#define _glMultMatrixfProcPtr(...) \
    callWithGLCheck(glMultMatrixfProcPtr, __VA_ARGS__)
#define _glMultTransposeMatrixd(...) \
    callWithGLCheck(glMultTransposeMatrixd, __VA_ARGS__)
#define _glMultTransposeMatrixdProcPtr(...) \
    callWithGLCheck(glMultTransposeMatrixdProcPtr, __VA_ARGS__)
#define _glMultTransposeMatrixf(...) \
    callWithGLCheck(glMultTransposeMatrixf, __VA_ARGS__)
#define _glMultTransposeMatrixfProcPtr(...) \
    callWithGLCheck(glMultTransposeMatrixfProcPtr, __VA_ARGS__)
#define _glMultiDrawArrays(...) callWithGLCheck(glMultiDrawArrays, __VA_ARGS__)
#define _glMultiDrawArraysProcPtr(...) \
    callWithGLCheck(glMultiDrawArraysProcPtr, __VA_ARGS__)
#define _glMultiDrawElements(...) \
    callWithGLCheck(glMultiDrawElements, __VA_ARGS__)
#define _glMultiDrawElementsProcPtr(...) \
    callWithGLCheck(glMultiDrawElementsProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1d(...) callWithGLCheck(glMultiTexCoord1d, __VA_ARGS__)
#define _glMultiTexCoord1dProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1dProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1dv(...) \
    callWithGLCheck(glMultiTexCoord1dv, __VA_ARGS__)
#define _glMultiTexCoord1dvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1dvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1f(...) callWithGLCheck(glMultiTexCoord1f, __VA_ARGS__)
#define _glMultiTexCoord1fProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1fProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1fv(...) \
    callWithGLCheck(glMultiTexCoord1fv, __VA_ARGS__)
#define _glMultiTexCoord1fvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1fvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1i(...) callWithGLCheck(glMultiTexCoord1i, __VA_ARGS__)
#define _glMultiTexCoord1iProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1iProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1iv(...) \
    callWithGLCheck(glMultiTexCoord1iv, __VA_ARGS__)
#define _glMultiTexCoord1ivProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1ivProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1s(...) callWithGLCheck(glMultiTexCoord1s, __VA_ARGS__)
#define _glMultiTexCoord1sProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1sProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1sv(...) \
    callWithGLCheck(glMultiTexCoord1sv, __VA_ARGS__)
#define _glMultiTexCoord1svProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1svProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2d(...) callWithGLCheck(glMultiTexCoord2d, __VA_ARGS__)
#define _glMultiTexCoord2dProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2dProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2dv(...) \
    callWithGLCheck(glMultiTexCoord2dv, __VA_ARGS__)
#define _glMultiTexCoord2dvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2dvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2f(...) callWithGLCheck(glMultiTexCoord2f, __VA_ARGS__)
#define _glMultiTexCoord2fProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2fProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2fv(...) \
    callWithGLCheck(glMultiTexCoord2fv, __VA_ARGS__)
#define _glMultiTexCoord2fvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2fvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2i(...) callWithGLCheck(glMultiTexCoord2i, __VA_ARGS__)
#define _glMultiTexCoord2iProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2iProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2iv(...) \
    callWithGLCheck(glMultiTexCoord2iv, __VA_ARGS__)
#define _glMultiTexCoord2ivProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2ivProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2s(...) callWithGLCheck(glMultiTexCoord2s, __VA_ARGS__)
#define _glMultiTexCoord2sProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2sProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2sv(...) \
    callWithGLCheck(glMultiTexCoord2sv, __VA_ARGS__)
#define _glMultiTexCoord2svProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2svProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3d(...) callWithGLCheck(glMultiTexCoord3d, __VA_ARGS__)
#define _glMultiTexCoord3dProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3dProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3dv(...) \
    callWithGLCheck(glMultiTexCoord3dv, __VA_ARGS__)
#define _glMultiTexCoord3dvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3dvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3f(...) callWithGLCheck(glMultiTexCoord3f, __VA_ARGS__)
#define _glMultiTexCoord3fProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3fProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3fv(...) \
    callWithGLCheck(glMultiTexCoord3fv, __VA_ARGS__)
#define _glMultiTexCoord3fvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3fvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3i(...) callWithGLCheck(glMultiTexCoord3i, __VA_ARGS__)
#define _glMultiTexCoord3iProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3iProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3iv(...) \
    callWithGLCheck(glMultiTexCoord3iv, __VA_ARGS__)
#define _glMultiTexCoord3ivProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3ivProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3s(...) callWithGLCheck(glMultiTexCoord3s, __VA_ARGS__)
#define _glMultiTexCoord3sProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3sProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3sv(...) \
    callWithGLCheck(glMultiTexCoord3sv, __VA_ARGS__)
#define _glMultiTexCoord3svProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3svProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4d(...) callWithGLCheck(glMultiTexCoord4d, __VA_ARGS__)
#define _glMultiTexCoord4dProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4dProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4dv(...) \
    callWithGLCheck(glMultiTexCoord4dv, __VA_ARGS__)
#define _glMultiTexCoord4dvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4dvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4f(...) callWithGLCheck(glMultiTexCoord4f, __VA_ARGS__)
#define _glMultiTexCoord4fProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4fProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4fv(...) \
    callWithGLCheck(glMultiTexCoord4fv, __VA_ARGS__)
#define _glMultiTexCoord4fvProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4fvProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4i(...) callWithGLCheck(glMultiTexCoord4i, __VA_ARGS__)
#define _glMultiTexCoord4iProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4iProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4iv(...) \
    callWithGLCheck(glMultiTexCoord4iv, __VA_ARGS__)
#define _glMultiTexCoord4ivProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4ivProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4s(...) callWithGLCheck(glMultiTexCoord4s, __VA_ARGS__)
#define _glMultiTexCoord4sProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4sProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4sv(...) \
    callWithGLCheck(glMultiTexCoord4sv, __VA_ARGS__)
#define _glMultiTexCoord4svProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4svProcPtr, __VA_ARGS__)
#define _glNewList(...) callWithGLCheck(glNewList, __VA_ARGS__)
#define _glNewListProcPtr(...) callWithGLCheck(glNewListProcPtr, __VA_ARGS__)
#define _glNormal3b(...) callWithGLCheck(glNormal3b, __VA_ARGS__)
#define _glNormal3bProcPtr(...) callWithGLCheck(glNormal3bProcPtr, __VA_ARGS__)
#define _glNormal3bv(...) callWithGLCheck(glNormal3bv, __VA_ARGS__)
#define _glNormal3bvProcPtr(...) \
    callWithGLCheck(glNormal3bvProcPtr, __VA_ARGS__)
#define _glNormal3d(...) callWithGLCheck(glNormal3d, __VA_ARGS__)
#define _glNormal3dProcPtr(...) callWithGLCheck(glNormal3dProcPtr, __VA_ARGS__)
#define _glNormal3dv(...) callWithGLCheck(glNormal3dv, __VA_ARGS__)
#define _glNormal3dvProcPtr(...) \
    callWithGLCheck(glNormal3dvProcPtr, __VA_ARGS__)
#define _glNormal3f(...) callWithGLCheck(glNormal3f, __VA_ARGS__)
#define _glNormal3fProcPtr(...) callWithGLCheck(glNormal3fProcPtr, __VA_ARGS__)
#define _glNormal3fv(...) callWithGLCheck(glNormal3fv, __VA_ARGS__)
#define _glNormal3fvProcPtr(...) \
    callWithGLCheck(glNormal3fvProcPtr, __VA_ARGS__)
#define _glNormal3i(...) callWithGLCheck(glNormal3i, __VA_ARGS__)
#define _glNormal3iProcPtr(...) callWithGLCheck(glNormal3iProcPtr, __VA_ARGS__)
#define _glNormal3iv(...) callWithGLCheck(glNormal3iv, __VA_ARGS__)
#define _glNormal3ivProcPtr(...) \
    callWithGLCheck(glNormal3ivProcPtr, __VA_ARGS__)
#define _glNormal3s(...) callWithGLCheck(glNormal3s, __VA_ARGS__)
#define _glNormal3sProcPtr(...) callWithGLCheck(glNormal3sProcPtr, __VA_ARGS__)
#define _glNormal3sv(...) callWithGLCheck(glNormal3sv, __VA_ARGS__)
#define _glNormal3svProcPtr(...) \
    callWithGLCheck(glNormal3svProcPtr, __VA_ARGS__)
#define _glNormalPointer(...) callWithGLCheck(glNormalPointer, __VA_ARGS__)
#define _glNormalPointerProcPtr(...) \
    callWithGLCheck(glNormalPointerProcPtr, __VA_ARGS__)
#define _glOrtho(...) callWithGLCheck(glOrtho, __VA_ARGS__)
#define _glOrthoProcPtr(...) callWithGLCheck(glOrthoProcPtr, __VA_ARGS__)
#define _glPassThrough(...) callWithGLCheck(glPassThrough, __VA_ARGS__)
#define _glPassThroughProcPtr(...) \
    callWithGLCheck(glPassThroughProcPtr, __VA_ARGS__)
#define _glPixelMapfv(...) callWithGLCheck(glPixelMapfv, __VA_ARGS__)
#define _glPixelMapfvProcPtr(...) \
    callWithGLCheck(glPixelMapfvProcPtr, __VA_ARGS__)
#define _glPixelMapuiv(...) callWithGLCheck(glPixelMapuiv, __VA_ARGS__)
#define _glPixelMapuivProcPtr(...) \
    callWithGLCheck(glPixelMapuivProcPtr, __VA_ARGS__)
#define _glPixelMapusv(...) callWithGLCheck(glPixelMapusv, __VA_ARGS__)
#define _glPixelMapusvProcPtr(...) \
    callWithGLCheck(glPixelMapusvProcPtr, __VA_ARGS__)
#define _glPixelStoref(...) callWithGLCheck(glPixelStoref, __VA_ARGS__)
#define _glPixelStorefProcPtr(...) \
    callWithGLCheck(glPixelStorefProcPtr, __VA_ARGS__)
#define _glPixelStorei(...) callWithGLCheck(glPixelStorei, __VA_ARGS__)
#define _glPixelStoreiProcPtr(...) \
    callWithGLCheck(glPixelStoreiProcPtr, __VA_ARGS__)
#define _glPixelTransferf(...) callWithGLCheck(glPixelTransferf, __VA_ARGS__)
#define _glPixelTransferfProcPtr(...) \
    callWithGLCheck(glPixelTransferfProcPtr, __VA_ARGS__)
#define _glPixelTransferi(...) callWithGLCheck(glPixelTransferi, __VA_ARGS__)
#define _glPixelTransferiProcPtr(...) \
    callWithGLCheck(glPixelTransferiProcPtr, __VA_ARGS__)
#define _glPixelZoom(...) callWithGLCheck(glPixelZoom, __VA_ARGS__)
#define _glPixelZoomProcPtr(...) \
    callWithGLCheck(glPixelZoomProcPtr, __VA_ARGS__)
#define _glPointParameterf(...) callWithGLCheck(glPointParameterf, __VA_ARGS__)
#define _glPointParameterfProcPtr(...) \
    callWithGLCheck(glPointParameterfProcPtr, __VA_ARGS__)
#define _glPointParameterfv(...) \
    callWithGLCheck(glPointParameterfv, __VA_ARGS__)
#define _glPointParameterfvProcPtr(...) \
    callWithGLCheck(glPointParameterfvProcPtr, __VA_ARGS__)
#define _glPointParameteri(...) callWithGLCheck(glPointParameteri, __VA_ARGS__)
#define _glPointParameteriProcPtr(...) \
    callWithGLCheck(glPointParameteriProcPtr, __VA_ARGS__)
#define _glPointParameteriv(...) \
    callWithGLCheck(glPointParameteriv, __VA_ARGS__)
#define _glPointParameterivProcPtr(...) \
    callWithGLCheck(glPointParameterivProcPtr, __VA_ARGS__)
#define _glPointSize(...) callWithGLCheck(glPointSize, __VA_ARGS__)
#define _glPointSizeProcPtr(...) \
    callWithGLCheck(glPointSizeProcPtr, __VA_ARGS__)
#define _glPolygonMode(...) callWithGLCheck(glPolygonMode, __VA_ARGS__)
#define _glPolygonModeProcPtr(...) \
    callWithGLCheck(glPolygonModeProcPtr, __VA_ARGS__)
#define _glPolygonOffset(...) callWithGLCheck(glPolygonOffset, __VA_ARGS__)
#define _glPolygonOffsetProcPtr(...) \
    callWithGLCheck(glPolygonOffsetProcPtr, __VA_ARGS__)
#define _glPolygonStipple(...) callWithGLCheck(glPolygonStipple, __VA_ARGS__)
#define _glPolygonStippleProcPtr(...) \
    callWithGLCheck(glPolygonStippleProcPtr, __VA_ARGS__)
#define _glPopAttrib(...) callWithGLCheck(glPopAttrib, __VA_ARGS__)
#define _glPopAttribProcPtr(...) \
    callWithGLCheck(glPopAttribProcPtr, __VA_ARGS__)
#define _glPopClientAttrib(...) callWithGLCheck(glPopClientAttrib, __VA_ARGS__)
#define _glPopClientAttribProcPtr(...) \
    callWithGLCheck(glPopClientAttribProcPtr, __VA_ARGS__)
#define _glPopMatrix(...) callWithGLCheck(glPopMatrix, __VA_ARGS__)
#define _glPopMatrixProcPtr(...) \
    callWithGLCheck(glPopMatrixProcPtr, __VA_ARGS__)
#define _glPopName(...) callWithGLCheck(glPopName, __VA_ARGS__)
#define _glPopNameProcPtr(...) callWithGLCheck(glPopNameProcPtr, __VA_ARGS__)
#define _glPrioritizeTextures(...) \
    callWithGLCheck(glPrioritizeTextures, __VA_ARGS__)
#define _glPrioritizeTexturesProcPtr(...) \
    callWithGLCheck(glPrioritizeTexturesProcPtr, __VA_ARGS__)
#define _glPushAttrib(...) callWithGLCheck(glPushAttrib, __VA_ARGS__)
#define _glPushAttribProcPtr(...) \
    callWithGLCheck(glPushAttribProcPtr, __VA_ARGS__)
#define _glPushClientAttrib(...) \
    callWithGLCheck(glPushClientAttrib, __VA_ARGS__)
#define _glPushClientAttribProcPtr(...) \
    callWithGLCheck(glPushClientAttribProcPtr, __VA_ARGS__)
#define _glPushMatrix(...) callWithGLCheck(glPushMatrix, __VA_ARGS__)
#define _glPushMatrixProcPtr(...) \
    callWithGLCheck(glPushMatrixProcPtr, __VA_ARGS__)
#define _glPushName(...) callWithGLCheck(glPushName, __VA_ARGS__)
#define _glPushNameProcPtr(...) callWithGLCheck(glPushNameProcPtr, __VA_ARGS__)
#define _glRasterPos2d(...) callWithGLCheck(glRasterPos2d, __VA_ARGS__)
#define _glRasterPos2dProcPtr(...) \
    callWithGLCheck(glRasterPos2dProcPtr, __VA_ARGS__)
#define _glRasterPos2dv(...) callWithGLCheck(glRasterPos2dv, __VA_ARGS__)
#define _glRasterPos2dvProcPtr(...) \
    callWithGLCheck(glRasterPos2dvProcPtr, __VA_ARGS__)
#define _glRasterPos2f(...) callWithGLCheck(glRasterPos2f, __VA_ARGS__)
#define _glRasterPos2fProcPtr(...) \
    callWithGLCheck(glRasterPos2fProcPtr, __VA_ARGS__)
#define _glRasterPos2fv(...) callWithGLCheck(glRasterPos2fv, __VA_ARGS__)
#define _glRasterPos2fvProcPtr(...) \
    callWithGLCheck(glRasterPos2fvProcPtr, __VA_ARGS__)
#define _glRasterPos2i(...) callWithGLCheck(glRasterPos2i, __VA_ARGS__)
#define _glRasterPos2iProcPtr(...) \
    callWithGLCheck(glRasterPos2iProcPtr, __VA_ARGS__)
#define _glRasterPos2iv(...) callWithGLCheck(glRasterPos2iv, __VA_ARGS__)
#define _glRasterPos2ivProcPtr(...) \
    callWithGLCheck(glRasterPos2ivProcPtr, __VA_ARGS__)
#define _glRasterPos2s(...) callWithGLCheck(glRasterPos2s, __VA_ARGS__)
#define _glRasterPos2sProcPtr(...) \
    callWithGLCheck(glRasterPos2sProcPtr, __VA_ARGS__)
#define _glRasterPos2sv(...) callWithGLCheck(glRasterPos2sv, __VA_ARGS__)
#define _glRasterPos2svProcPtr(...) \
    callWithGLCheck(glRasterPos2svProcPtr, __VA_ARGS__)
#define _glRasterPos3d(...) callWithGLCheck(glRasterPos3d, __VA_ARGS__)
#define _glRasterPos3dProcPtr(...) \
    callWithGLCheck(glRasterPos3dProcPtr, __VA_ARGS__)
#define _glRasterPos3dv(...) callWithGLCheck(glRasterPos3dv, __VA_ARGS__)
#define _glRasterPos3dvProcPtr(...) \
    callWithGLCheck(glRasterPos3dvProcPtr, __VA_ARGS__)
#define _glRasterPos3f(...) callWithGLCheck(glRasterPos3f, __VA_ARGS__)
#define _glRasterPos3fProcPtr(...) \
    callWithGLCheck(glRasterPos3fProcPtr, __VA_ARGS__)
#define _glRasterPos3fv(...) callWithGLCheck(glRasterPos3fv, __VA_ARGS__)
#define _glRasterPos3fvProcPtr(...) \
    callWithGLCheck(glRasterPos3fvProcPtr, __VA_ARGS__)
#define _glRasterPos3i(...) callWithGLCheck(glRasterPos3i, __VA_ARGS__)
#define _glRasterPos3iProcPtr(...) \
    callWithGLCheck(glRasterPos3iProcPtr, __VA_ARGS__)
#define _glRasterPos3iv(...) callWithGLCheck(glRasterPos3iv, __VA_ARGS__)
#define _glRasterPos3ivProcPtr(...) \
    callWithGLCheck(glRasterPos3ivProcPtr, __VA_ARGS__)
#define _glRasterPos3s(...) callWithGLCheck(glRasterPos3s, __VA_ARGS__)
#define _glRasterPos3sProcPtr(...) \
    callWithGLCheck(glRasterPos3sProcPtr, __VA_ARGS__)
#define _glRasterPos3sv(...) callWithGLCheck(glRasterPos3sv, __VA_ARGS__)
#define _glRasterPos3svProcPtr(...) \
    callWithGLCheck(glRasterPos3svProcPtr, __VA_ARGS__)
#define _glRasterPos4d(...) callWithGLCheck(glRasterPos4d, __VA_ARGS__)
#define _glRasterPos4dProcPtr(...) \
    callWithGLCheck(glRasterPos4dProcPtr, __VA_ARGS__)
#define _glRasterPos4dv(...) callWithGLCheck(glRasterPos4dv, __VA_ARGS__)
#define _glRasterPos4dvProcPtr(...) \
    callWithGLCheck(glRasterPos4dvProcPtr, __VA_ARGS__)
#define _glRasterPos4f(...) callWithGLCheck(glRasterPos4f, __VA_ARGS__)
#define _glRasterPos4fProcPtr(...) \
    callWithGLCheck(glRasterPos4fProcPtr, __VA_ARGS__)
#define _glRasterPos4fv(...) callWithGLCheck(glRasterPos4fv, __VA_ARGS__)
#define _glRasterPos4fvProcPtr(...) \
    callWithGLCheck(glRasterPos4fvProcPtr, __VA_ARGS__)
#define _glRasterPos4i(...) callWithGLCheck(glRasterPos4i, __VA_ARGS__)
#define _glRasterPos4iProcPtr(...) \
    callWithGLCheck(glRasterPos4iProcPtr, __VA_ARGS__)
#define _glRasterPos4iv(...) callWithGLCheck(glRasterPos4iv, __VA_ARGS__)
#define _glRasterPos4ivProcPtr(...) \
    callWithGLCheck(glRasterPos4ivProcPtr, __VA_ARGS__)
#define _glRasterPos4s(...) callWithGLCheck(glRasterPos4s, __VA_ARGS__)
#define _glRasterPos4sProcPtr(...) \
    callWithGLCheck(glRasterPos4sProcPtr, __VA_ARGS__)
#define _glRasterPos4sv(...) callWithGLCheck(glRasterPos4sv, __VA_ARGS__)
#define _glRasterPos4svProcPtr(...) \
    callWithGLCheck(glRasterPos4svProcPtr, __VA_ARGS__)
#define _glReadBuffer(...) callWithGLCheck(glReadBuffer, __VA_ARGS__)
#define _glReadBufferProcPtr(...) \
    callWithGLCheck(glReadBufferProcPtr, __VA_ARGS__)
#define _glReadPixels(...) callWithGLCheck(glReadPixels, __VA_ARGS__)
#define _glReadPixelsProcPtr(...) \
    callWithGLCheck(glReadPixelsProcPtr, __VA_ARGS__)
#define _glRectd(...) callWithGLCheck(glRectd, __VA_ARGS__)
#define _glRectdProcPtr(...) callWithGLCheck(glRectdProcPtr, __VA_ARGS__)
#define _glRectdv(...) callWithGLCheck(glRectdv, __VA_ARGS__)
#define _glRectdvProcPtr(...) callWithGLCheck(glRectdvProcPtr, __VA_ARGS__)
#define _glRectf(...) callWithGLCheck(glRectf, __VA_ARGS__)
#define _glRectfProcPtr(...) callWithGLCheck(glRectfProcPtr, __VA_ARGS__)
#define _glRectfv(...) callWithGLCheck(glRectfv, __VA_ARGS__)
#define _glRectfvProcPtr(...) callWithGLCheck(glRectfvProcPtr, __VA_ARGS__)
#define _glRecti(...) callWithGLCheck(glRecti, __VA_ARGS__)
#define _glRectiProcPtr(...) callWithGLCheck(glRectiProcPtr, __VA_ARGS__)
#define _glRectiv(...) callWithGLCheck(glRectiv, __VA_ARGS__)
#define _glRectivProcPtr(...) callWithGLCheck(glRectivProcPtr, __VA_ARGS__)
#define _glRects(...) callWithGLCheck(glRects, __VA_ARGS__)
#define _glRectsProcPtr(...) callWithGLCheck(glRectsProcPtr, __VA_ARGS__)
#define _glRectsv(...) callWithGLCheck(glRectsv, __VA_ARGS__)
#define _glRectsvProcPtr(...) callWithGLCheck(glRectsvProcPtr, __VA_ARGS__)
#define _glRenderMode(...) callWithGLCheck(glRenderMode, __VA_ARGS__)
#define _glRenderModeProcPtr(...) \
    callWithGLCheck(glRenderModeProcPtr, __VA_ARGS__)
#define _glResetHistogram(...) callWithGLCheck(glResetHistogram, __VA_ARGS__)
#define _glResetHistogramProcPtr(...) \
    callWithGLCheck(glResetHistogramProcPtr, __VA_ARGS__)
#define _glResetMinmax(...) callWithGLCheck(glResetMinmax, __VA_ARGS__)
#define _glResetMinmaxProcPtr(...) \
    callWithGLCheck(glResetMinmaxProcPtr, __VA_ARGS__)
#define _glRotated(...) callWithGLCheck(glRotated, __VA_ARGS__)
#define _glRotatedProcPtr(...) callWithGLCheck(glRotatedProcPtr, __VA_ARGS__)
#define _glRotatef(...) callWithGLCheck(glRotatef, __VA_ARGS__)
#define _glRotatefProcPtr(...) callWithGLCheck(glRotatefProcPtr, __VA_ARGS__)
#define _glSampleCoverage(...) callWithGLCheck(glSampleCoverage, __VA_ARGS__)
#define _glSampleCoverageProcPtr(...) \
    callWithGLCheck(glSampleCoverageProcPtr, __VA_ARGS__)
#define _glScaled(...) callWithGLCheck(glScaled, __VA_ARGS__)
#define _glScaledProcPtr(...) callWithGLCheck(glScaledProcPtr, __VA_ARGS__)
#define _glScalef(...) callWithGLCheck(glScalef, __VA_ARGS__)
#define _glScalefProcPtr(...) callWithGLCheck(glScalefProcPtr, __VA_ARGS__)
#define _glScissor(...) callWithGLCheck(glScissor, __VA_ARGS__)
#define _glScissorProcPtr(...) callWithGLCheck(glScissorProcPtr, __VA_ARGS__)
#define _glSecondaryColor3b(...) \
    callWithGLCheck(glSecondaryColor3b, __VA_ARGS__)
#define _glSecondaryColor3bProcPtr(...) \
    callWithGLCheck(glSecondaryColor3bProcPtr, __VA_ARGS__)
#define _glSecondaryColor3bv(...) \
    callWithGLCheck(glSecondaryColor3bv, __VA_ARGS__)
#define _glSecondaryColor3bvProcPtr(...) \
    callWithGLCheck(glSecondaryColor3bvProcPtr, __VA_ARGS__)
#define _glSecondaryColor3d(...) \
    callWithGLCheck(glSecondaryColor3d, __VA_ARGS__)
#define _glSecondaryColor3dProcPtr(...) \
    callWithGLCheck(glSecondaryColor3dProcPtr, __VA_ARGS__)
#define _glSecondaryColor3dv(...) \
    callWithGLCheck(glSecondaryColor3dv, __VA_ARGS__)
#define _glSecondaryColor3dvProcPtr(...) \
    callWithGLCheck(glSecondaryColor3dvProcPtr, __VA_ARGS__)
#define _glSecondaryColor3f(...) \
    callWithGLCheck(glSecondaryColor3f, __VA_ARGS__)
#define _glSecondaryColor3fProcPtr(...) \
    callWithGLCheck(glSecondaryColor3fProcPtr, __VA_ARGS__)
#define _glSecondaryColor3fv(...) \
    callWithGLCheck(glSecondaryColor3fv, __VA_ARGS__)
#define _glSecondaryColor3fvProcPtr(...) \
    callWithGLCheck(glSecondaryColor3fvProcPtr, __VA_ARGS__)
#define _glSecondaryColor3i(...) \
    callWithGLCheck(glSecondaryColor3i, __VA_ARGS__)
#define _glSecondaryColor3iProcPtr(...) \
    callWithGLCheck(glSecondaryColor3iProcPtr, __VA_ARGS__)
#define _glSecondaryColor3iv(...) \
    callWithGLCheck(glSecondaryColor3iv, __VA_ARGS__)
#define _glSecondaryColor3ivProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ivProcPtr, __VA_ARGS__)
#define _glSecondaryColor3s(...) \
    callWithGLCheck(glSecondaryColor3s, __VA_ARGS__)
#define _glSecondaryColor3sProcPtr(...) \
    callWithGLCheck(glSecondaryColor3sProcPtr, __VA_ARGS__)
#define _glSecondaryColor3sv(...) \
    callWithGLCheck(glSecondaryColor3sv, __VA_ARGS__)
#define _glSecondaryColor3svProcPtr(...) \
    callWithGLCheck(glSecondaryColor3svProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ub(...) \
    callWithGLCheck(glSecondaryColor3ub, __VA_ARGS__)
#define _glSecondaryColor3ubProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ubProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ubv(...) \
    callWithGLCheck(glSecondaryColor3ubv, __VA_ARGS__)
#define _glSecondaryColor3ubvProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ubvProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ui(...) \
    callWithGLCheck(glSecondaryColor3ui, __VA_ARGS__)
#define _glSecondaryColor3uiProcPtr(...) \
    callWithGLCheck(glSecondaryColor3uiProcPtr, __VA_ARGS__)
#define _glSecondaryColor3uiv(...) \
    callWithGLCheck(glSecondaryColor3uiv, __VA_ARGS__)
#define _glSecondaryColor3uivProcPtr(...) \
    callWithGLCheck(glSecondaryColor3uivProcPtr, __VA_ARGS__)
#define _glSecondaryColor3us(...) \
    callWithGLCheck(glSecondaryColor3us, __VA_ARGS__)
#define _glSecondaryColor3usProcPtr(...) \
    callWithGLCheck(glSecondaryColor3usProcPtr, __VA_ARGS__)
#define _glSecondaryColor3usv(...) \
    callWithGLCheck(glSecondaryColor3usv, __VA_ARGS__)
#define _glSecondaryColor3usvProcPtr(...) \
    callWithGLCheck(glSecondaryColor3usvProcPtr, __VA_ARGS__)
#define _glSecondaryColorPointer(...) \
    callWithGLCheck(glSecondaryColorPointer, __VA_ARGS__)
#define _glSecondaryColorPointerProcPtr(...) \
    callWithGLCheck(glSecondaryColorPointerProcPtr, __VA_ARGS__)
#define _glSelectBuffer(...) callWithGLCheck(glSelectBuffer, __VA_ARGS__)
#define _glSelectBufferProcPtr(...) \
    callWithGLCheck(glSelectBufferProcPtr, __VA_ARGS__)
#define _glSeparableFilter2D(...) \
    callWithGLCheck(glSeparableFilter2D, __VA_ARGS__)
#define _glSeparableFilter2DProcPtr(...) \
    callWithGLCheck(glSeparableFilter2DProcPtr, __VA_ARGS__)
#define _glShadeModel(...) callWithGLCheck(glShadeModel, __VA_ARGS__)
#define _glShadeModelProcPtr(...) \
    callWithGLCheck(glShadeModelProcPtr, __VA_ARGS__)
#define _glShaderSource(...) callWithGLCheck(glShaderSource, __VA_ARGS__)
#define _glShaderSourceProcPtr(...) \
    callWithGLCheck(glShaderSourceProcPtr, __VA_ARGS__)
#define _glStencilFunc(...) callWithGLCheck(glStencilFunc, __VA_ARGS__)
#define _glStencilFuncProcPtr(...) \
    callWithGLCheck(glStencilFuncProcPtr, __VA_ARGS__)
#define _glStencilFuncSeparate(...) \
    callWithGLCheck(glStencilFuncSeparate, __VA_ARGS__)
#define _glStencilFuncSeparateProcPtr(...) \
    callWithGLCheck(glStencilFuncSeparateProcPtr, __VA_ARGS__)
#define _glStencilMask(...) callWithGLCheck(glStencilMask, __VA_ARGS__)
#define _glStencilMaskProcPtr(...) \
    callWithGLCheck(glStencilMaskProcPtr, __VA_ARGS__)
#define _glStencilMaskSeparate(...) \
    callWithGLCheck(glStencilMaskSeparate, __VA_ARGS__)
#define _glStencilMaskSeparateProcPtr(...) \
    callWithGLCheck(glStencilMaskSeparateProcPtr, __VA_ARGS__)
#define _glStencilOp(...) callWithGLCheck(glStencilOp, __VA_ARGS__)
#define _glStencilOpProcPtr(...) \
    callWithGLCheck(glStencilOpProcPtr, __VA_ARGS__)
#define _glStencilOpSeparate(...) \
    callWithGLCheck(glStencilOpSeparate, __VA_ARGS__)
#define _glStencilOpSeparateProcPtr(...) \
    callWithGLCheck(glStencilOpSeparateProcPtr, __VA_ARGS__)
#define _glTexCoord1d(...) callWithGLCheck(glTexCoord1d, __VA_ARGS__)
#define _glTexCoord1dProcPtr(...) \
    callWithGLCheck(glTexCoord1dProcPtr, __VA_ARGS__)
#define _glTexCoord1dv(...) callWithGLCheck(glTexCoord1dv, __VA_ARGS__)
#define _glTexCoord1dvProcPtr(...) \
    callWithGLCheck(glTexCoord1dvProcPtr, __VA_ARGS__)
#define _glTexCoord1f(...) callWithGLCheck(glTexCoord1f, __VA_ARGS__)
#define _glTexCoord1fProcPtr(...) \
    callWithGLCheck(glTexCoord1fProcPtr, __VA_ARGS__)
#define _glTexCoord1fv(...) callWithGLCheck(glTexCoord1fv, __VA_ARGS__)
#define _glTexCoord1fvProcPtr(...) \
    callWithGLCheck(glTexCoord1fvProcPtr, __VA_ARGS__)
#define _glTexCoord1i(...) callWithGLCheck(glTexCoord1i, __VA_ARGS__)
#define _glTexCoord1iProcPtr(...) \
    callWithGLCheck(glTexCoord1iProcPtr, __VA_ARGS__)
#define _glTexCoord1iv(...) callWithGLCheck(glTexCoord1iv, __VA_ARGS__)
#define _glTexCoord1ivProcPtr(...) \
    callWithGLCheck(glTexCoord1ivProcPtr, __VA_ARGS__)
#define _glTexCoord1s(...) callWithGLCheck(glTexCoord1s, __VA_ARGS__)
#define _glTexCoord1sProcPtr(...) \
    callWithGLCheck(glTexCoord1sProcPtr, __VA_ARGS__)
#define _glTexCoord1sv(...) callWithGLCheck(glTexCoord1sv, __VA_ARGS__)
#define _glTexCoord1svProcPtr(...) \
    callWithGLCheck(glTexCoord1svProcPtr, __VA_ARGS__)
#define _glTexCoord2d(...) callWithGLCheck(glTexCoord2d, __VA_ARGS__)
#define _glTexCoord2dProcPtr(...) \
    callWithGLCheck(glTexCoord2dProcPtr, __VA_ARGS__)
#define _glTexCoord2dv(...) callWithGLCheck(glTexCoord2dv, __VA_ARGS__)
#define _glTexCoord2dvProcPtr(...) \
    callWithGLCheck(glTexCoord2dvProcPtr, __VA_ARGS__)
#define _glTexCoord2f(...) callWithGLCheck(glTexCoord2f, __VA_ARGS__)
#define _glTexCoord2fProcPtr(...) \
    callWithGLCheck(glTexCoord2fProcPtr, __VA_ARGS__)
#define _glTexCoord2fv(...) callWithGLCheck(glTexCoord2fv, __VA_ARGS__)
#define _glTexCoord2fvProcPtr(...) \
    callWithGLCheck(glTexCoord2fvProcPtr, __VA_ARGS__)
#define _glTexCoord2i(...) callWithGLCheck(glTexCoord2i, __VA_ARGS__)
#define _glTexCoord2iProcPtr(...) \
    callWithGLCheck(glTexCoord2iProcPtr, __VA_ARGS__)
#define _glTexCoord2iv(...) callWithGLCheck(glTexCoord2iv, __VA_ARGS__)
#define _glTexCoord2ivProcPtr(...) \
    callWithGLCheck(glTexCoord2ivProcPtr, __VA_ARGS__)
#define _glTexCoord2s(...) callWithGLCheck(glTexCoord2s, __VA_ARGS__)
#define _glTexCoord2sProcPtr(...) \
    callWithGLCheck(glTexCoord2sProcPtr, __VA_ARGS__)
#define _glTexCoord2sv(...) callWithGLCheck(glTexCoord2sv, __VA_ARGS__)
#define _glTexCoord2svProcPtr(...) \
    callWithGLCheck(glTexCoord2svProcPtr, __VA_ARGS__)
#define _glTexCoord3d(...) callWithGLCheck(glTexCoord3d, __VA_ARGS__)
#define _glTexCoord3dProcPtr(...) \
    callWithGLCheck(glTexCoord3dProcPtr, __VA_ARGS__)
#define _glTexCoord3dv(...) callWithGLCheck(glTexCoord3dv, __VA_ARGS__)
#define _glTexCoord3dvProcPtr(...) \
    callWithGLCheck(glTexCoord3dvProcPtr, __VA_ARGS__)
#define _glTexCoord3f(...) callWithGLCheck(glTexCoord3f, __VA_ARGS__)
#define _glTexCoord3fProcPtr(...) \
    callWithGLCheck(glTexCoord3fProcPtr, __VA_ARGS__)
#define _glTexCoord3fv(...) callWithGLCheck(glTexCoord3fv, __VA_ARGS__)
#define _glTexCoord3fvProcPtr(...) \
    callWithGLCheck(glTexCoord3fvProcPtr, __VA_ARGS__)
#define _glTexCoord3i(...) callWithGLCheck(glTexCoord3i, __VA_ARGS__)
#define _glTexCoord3iProcPtr(...) \
    callWithGLCheck(glTexCoord3iProcPtr, __VA_ARGS__)
#define _glTexCoord3iv(...) callWithGLCheck(glTexCoord3iv, __VA_ARGS__)
#define _glTexCoord3ivProcPtr(...) \
    callWithGLCheck(glTexCoord3ivProcPtr, __VA_ARGS__)
#define _glTexCoord3s(...) callWithGLCheck(glTexCoord3s, __VA_ARGS__)
#define _glTexCoord3sProcPtr(...) \
    callWithGLCheck(glTexCoord3sProcPtr, __VA_ARGS__)
#define _glTexCoord3sv(...) callWithGLCheck(glTexCoord3sv, __VA_ARGS__)
#define _glTexCoord3svProcPtr(...) \
    callWithGLCheck(glTexCoord3svProcPtr, __VA_ARGS__)
#define _glTexCoord4d(...) callWithGLCheck(glTexCoord4d, __VA_ARGS__)
#define _glTexCoord4dProcPtr(...) \
    callWithGLCheck(glTexCoord4dProcPtr, __VA_ARGS__)
#define _glTexCoord4dv(...) callWithGLCheck(glTexCoord4dv, __VA_ARGS__)
#define _glTexCoord4dvProcPtr(...) \
    callWithGLCheck(glTexCoord4dvProcPtr, __VA_ARGS__)
#define _glTexCoord4f(...) callWithGLCheck(glTexCoord4f, __VA_ARGS__)
#define _glTexCoord4fProcPtr(...) \
    callWithGLCheck(glTexCoord4fProcPtr, __VA_ARGS__)
#define _glTexCoord4fv(...) callWithGLCheck(glTexCoord4fv, __VA_ARGS__)
#define _glTexCoord4fvProcPtr(...) \
    callWithGLCheck(glTexCoord4fvProcPtr, __VA_ARGS__)
#define _glTexCoord4i(...) callWithGLCheck(glTexCoord4i, __VA_ARGS__)
#define _glTexCoord4iProcPtr(...) \
    callWithGLCheck(glTexCoord4iProcPtr, __VA_ARGS__)
#define _glTexCoord4iv(...) callWithGLCheck(glTexCoord4iv, __VA_ARGS__)
#define _glTexCoord4ivProcPtr(...) \
    callWithGLCheck(glTexCoord4ivProcPtr, __VA_ARGS__)
#define _glTexCoord4s(...) callWithGLCheck(glTexCoord4s, __VA_ARGS__)
#define _glTexCoord4sProcPtr(...) \
    callWithGLCheck(glTexCoord4sProcPtr, __VA_ARGS__)
#define _glTexCoord4sv(...) callWithGLCheck(glTexCoord4sv, __VA_ARGS__)
#define _glTexCoord4svProcPtr(...) \
    callWithGLCheck(glTexCoord4svProcPtr, __VA_ARGS__)
#define _glTexCoordPointer(...) callWithGLCheck(glTexCoordPointer, __VA_ARGS__)
#define _glTexCoordPointerProcPtr(...) \
    callWithGLCheck(glTexCoordPointerProcPtr, __VA_ARGS__)
#define _glTexEnvf(...) callWithGLCheck(glTexEnvf, __VA_ARGS__)
#define _glTexEnvfProcPtr(...) callWithGLCheck(glTexEnvfProcPtr, __VA_ARGS__)
#define _glTexEnvfv(...) callWithGLCheck(glTexEnvfv, __VA_ARGS__)
#define _glTexEnvfvProcPtr(...) callWithGLCheck(glTexEnvfvProcPtr, __VA_ARGS__)
#define _glTexEnvi(...) callWithGLCheck(glTexEnvi, __VA_ARGS__)
#define _glTexEnviProcPtr(...) callWithGLCheck(glTexEnviProcPtr, __VA_ARGS__)
#define _glTexEnviv(...) callWithGLCheck(glTexEnviv, __VA_ARGS__)
#define _glTexEnvivProcPtr(...) callWithGLCheck(glTexEnvivProcPtr, __VA_ARGS__)
#define _glTexGend(...) callWithGLCheck(glTexGend, __VA_ARGS__)
#define _glTexGendProcPtr(...) callWithGLCheck(glTexGendProcPtr, __VA_ARGS__)
#define _glTexGendv(...) callWithGLCheck(glTexGendv, __VA_ARGS__)
#define _glTexGendvProcPtr(...) callWithGLCheck(glTexGendvProcPtr, __VA_ARGS__)
#define _glTexGenf(...) callWithGLCheck(glTexGenf, __VA_ARGS__)
#define _glTexGenfProcPtr(...) callWithGLCheck(glTexGenfProcPtr, __VA_ARGS__)
#define _glTexGenfv(...) callWithGLCheck(glTexGenfv, __VA_ARGS__)
#define _glTexGenfvProcPtr(...) callWithGLCheck(glTexGenfvProcPtr, __VA_ARGS__)
#define _glTexGeni(...) callWithGLCheck(glTexGeni, __VA_ARGS__)
#define _glTexGeniProcPtr(...) callWithGLCheck(glTexGeniProcPtr, __VA_ARGS__)
#define _glTexGeniv(...) callWithGLCheck(glTexGeniv, __VA_ARGS__)
#define _glTexGenivProcPtr(...) callWithGLCheck(glTexGenivProcPtr, __VA_ARGS__)
#define _glTexImage1D(...) callWithGLCheck(glTexImage1D, __VA_ARGS__)
#define _glTexImage1DProcPtr(...) \
    callWithGLCheck(glTexImage1DProcPtr, __VA_ARGS__)
#define _glTexImage2D(...) callWithGLCheck(glTexImage2D, __VA_ARGS__)
#define _glTexImage2DProcPtr(...) \
    callWithGLCheck(glTexImage2DProcPtr, __VA_ARGS__)
#define _glTexImage3D(...) callWithGLCheck(glTexImage3D, __VA_ARGS__)
#define _glTexImage3DProcPtr(...) \
    callWithGLCheck(glTexImage3DProcPtr, __VA_ARGS__)
#define _glTexParameterf(...) callWithGLCheck(glTexParameterf, __VA_ARGS__)
#define _glTexParameterfProcPtr(...) \
    callWithGLCheck(glTexParameterfProcPtr, __VA_ARGS__)
#define _glTexParameterfv(...) callWithGLCheck(glTexParameterfv, __VA_ARGS__)
#define _glTexParameterfvProcPtr(...) \
    callWithGLCheck(glTexParameterfvProcPtr, __VA_ARGS__)
#define _glTexParameteri(...) callWithGLCheck(glTexParameteri, __VA_ARGS__)
#define _glTexParameteriProcPtr(...) \
    callWithGLCheck(glTexParameteriProcPtr, __VA_ARGS__)
#define _glTexParameteriv(...) callWithGLCheck(glTexParameteriv, __VA_ARGS__)
#define _glTexParameterivProcPtr(...) \
    callWithGLCheck(glTexParameterivProcPtr, __VA_ARGS__)
#define _glTexSubImage1D(...) callWithGLCheck(glTexSubImage1D, __VA_ARGS__)
#define _glTexSubImage1DProcPtr(...) \
    callWithGLCheck(glTexSubImage1DProcPtr, __VA_ARGS__)
#define _glTexSubImage2D(...) callWithGLCheck(glTexSubImage2D, __VA_ARGS__)
#define _glTexSubImage2DProcPtr(...) \
    callWithGLCheck(glTexSubImage2DProcPtr, __VA_ARGS__)
#define _glTexSubImage3D(...) callWithGLCheck(glTexSubImage3D, __VA_ARGS__)
#define _glTexSubImage3DProcPtr(...) \
    callWithGLCheck(glTexSubImage3DProcPtr, __VA_ARGS__)
#define _glTranslated(...) callWithGLCheck(glTranslated, __VA_ARGS__)
#define _glTranslatedProcPtr(...) \
    callWithGLCheck(glTranslatedProcPtr, __VA_ARGS__)
#define _glTranslatef(...) callWithGLCheck(glTranslatef, __VA_ARGS__)
#define _glTranslatefProcPtr(...) \
    callWithGLCheck(glTranslatefProcPtr, __VA_ARGS__)
#define _glUniform1f(...) callWithGLCheck(glUniform1f, __VA_ARGS__)
#define _glUniform1fProcPtr(...) \
    callWithGLCheck(glUniform1fProcPtr, __VA_ARGS__)
#define _glUniform1fv(...) callWithGLCheck(glUniform1fv, __VA_ARGS__)
#define _glUniform1fvProcPtr(...) \
    callWithGLCheck(glUniform1fvProcPtr, __VA_ARGS__)
#define _glUniform1i(...) callWithGLCheck(glUniform1i, __VA_ARGS__)
#define _glUniform1iProcPtr(...) \
    callWithGLCheck(glUniform1iProcPtr, __VA_ARGS__)
#define _glUniform1iv(...) callWithGLCheck(glUniform1iv, __VA_ARGS__)
#define _glUniform1ivProcPtr(...) \
    callWithGLCheck(glUniform1ivProcPtr, __VA_ARGS__)
#define _glUniform2f(...) callWithGLCheck(glUniform2f, __VA_ARGS__)
#define _glUniform2fProcPtr(...) \
    callWithGLCheck(glUniform2fProcPtr, __VA_ARGS__)
#define _glUniform2fv(...) callWithGLCheck(glUniform2fv, __VA_ARGS__)
#define _glUniform2fvProcPtr(...) \
    callWithGLCheck(glUniform2fvProcPtr, __VA_ARGS__)
#define _glUniform2i(...) callWithGLCheck(glUniform2i, __VA_ARGS__)
#define _glUniform2iProcPtr(...) \
    callWithGLCheck(glUniform2iProcPtr, __VA_ARGS__)
#define _glUniform2iv(...) callWithGLCheck(glUniform2iv, __VA_ARGS__)
#define _glUniform2ivProcPtr(...) \
    callWithGLCheck(glUniform2ivProcPtr, __VA_ARGS__)
#define _glUniform3f(...) callWithGLCheck(glUniform3f, __VA_ARGS__)
#define _glUniform3fProcPtr(...) \
    callWithGLCheck(glUniform3fProcPtr, __VA_ARGS__)
#define _glUniform3fv(...) callWithGLCheck(glUniform3fv, __VA_ARGS__)
#define _glUniform3fvProcPtr(...) \
    callWithGLCheck(glUniform3fvProcPtr, __VA_ARGS__)
#define _glUniform3i(...) callWithGLCheck(glUniform3i, __VA_ARGS__)
#define _glUniform3iProcPtr(...) \
    callWithGLCheck(glUniform3iProcPtr, __VA_ARGS__)
#define _glUniform3iv(...) callWithGLCheck(glUniform3iv, __VA_ARGS__)
#define _glUniform3ivProcPtr(...) \
    callWithGLCheck(glUniform3ivProcPtr, __VA_ARGS__)
#define _glUniform4f(...) callWithGLCheck(glUniform4f, __VA_ARGS__)
#define _glUniform4fProcPtr(...) \
    callWithGLCheck(glUniform4fProcPtr, __VA_ARGS__)
#define _glUniform4fv(...) callWithGLCheck(glUniform4fv, __VA_ARGS__)
#define _glUniform4fvProcPtr(...) \
    callWithGLCheck(glUniform4fvProcPtr, __VA_ARGS__)
#define _glUniform4i(...) callWithGLCheck(glUniform4i, __VA_ARGS__)
#define _glUniform4iProcPtr(...) \
    callWithGLCheck(glUniform4iProcPtr, __VA_ARGS__)
#define _glUniform4iv(...) callWithGLCheck(glUniform4iv, __VA_ARGS__)
#define _glUniform4ivProcPtr(...) \
    callWithGLCheck(glUniform4ivProcPtr, __VA_ARGS__)
#define _glUniformMatrix2fv(...) \
    callWithGLCheck(glUniformMatrix2fv, __VA_ARGS__)
#define _glUniformMatrix2fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix2fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix2x3fv(...) \
    callWithGLCheck(glUniformMatrix2x3fv, __VA_ARGS__)
#define _glUniformMatrix2x3fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix2x3fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix2x4fv(...) \
    callWithGLCheck(glUniformMatrix2x4fv, __VA_ARGS__)
#define _glUniformMatrix2x4fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix2x4fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix3fv(...) \
    callWithGLCheck(glUniformMatrix3fv, __VA_ARGS__)
#define _glUniformMatrix3fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix3fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix3x2fv(...) \
    callWithGLCheck(glUniformMatrix3x2fv, __VA_ARGS__)
#define _glUniformMatrix3x2fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix3x2fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix3x4fv(...) \
    callWithGLCheck(glUniformMatrix3x4fv, __VA_ARGS__)
#define _glUniformMatrix3x4fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix3x4fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix4fv(...) \
    callWithGLCheck(glUniformMatrix4fv, __VA_ARGS__)
#define _glUniformMatrix4fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix4fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix4x2fv(...) \
    callWithGLCheck(glUniformMatrix4x2fv, __VA_ARGS__)
#define _glUniformMatrix4x2fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix4x2fvProcPtr, __VA_ARGS__)
#define _glUniformMatrix4x3fv(...) \
    callWithGLCheck(glUniformMatrix4x3fv, __VA_ARGS__)
#define _glUniformMatrix4x3fvProcPtr(...) \
    callWithGLCheck(glUniformMatrix4x3fvProcPtr, __VA_ARGS__)
#define _glUnmapBuffer(...) callWithGLCheck(glUnmapBuffer, __VA_ARGS__)
#define _glUnmapBufferProcPtr(...) \
    callWithGLCheck(glUnmapBufferProcPtr, __VA_ARGS__)
#define _glUseProgram(...) callWithGLCheck(glUseProgram, __VA_ARGS__)
#define _glUseProgramProcPtr(...) \
    callWithGLCheck(glUseProgramProcPtr, __VA_ARGS__)
#define _glValidateProgram(...) callWithGLCheck(glValidateProgram, __VA_ARGS__)
#define _glValidateProgramProcPtr(...) \
    callWithGLCheck(glValidateProgramProcPtr, __VA_ARGS__)
#define _glVertex2d(...) callWithGLCheck(glVertex2d, __VA_ARGS__)
#define _glVertex2dProcPtr(...) callWithGLCheck(glVertex2dProcPtr, __VA_ARGS__)
#define _glVertex2dv(...) callWithGLCheck(glVertex2dv, __VA_ARGS__)
#define _glVertex2dvProcPtr(...) \
    callWithGLCheck(glVertex2dvProcPtr, __VA_ARGS__)
#define _glVertex2f(...) callWithGLCheck(glVertex2f, __VA_ARGS__)
#define _glVertex2fProcPtr(...) callWithGLCheck(glVertex2fProcPtr, __VA_ARGS__)
#define _glVertex2fv(...) callWithGLCheck(glVertex2fv, __VA_ARGS__)
#define _glVertex2fvProcPtr(...) \
    callWithGLCheck(glVertex2fvProcPtr, __VA_ARGS__)
#define _glVertex2i(...) callWithGLCheck(glVertex2i, __VA_ARGS__)
#define _glVertex2iProcPtr(...) callWithGLCheck(glVertex2iProcPtr, __VA_ARGS__)
#define _glVertex2iv(...) callWithGLCheck(glVertex2iv, __VA_ARGS__)
#define _glVertex2ivProcPtr(...) \
    callWithGLCheck(glVertex2ivProcPtr, __VA_ARGS__)
#define _glVertex2s(...) callWithGLCheck(glVertex2s, __VA_ARGS__)
#define _glVertex2sProcPtr(...) callWithGLCheck(glVertex2sProcPtr, __VA_ARGS__)
#define _glVertex2sv(...) callWithGLCheck(glVertex2sv, __VA_ARGS__)
#define _glVertex2svProcPtr(...) \
    callWithGLCheck(glVertex2svProcPtr, __VA_ARGS__)
#define _glVertex3d(...) callWithGLCheck(glVertex3d, __VA_ARGS__)
#define _glVertex3dProcPtr(...) callWithGLCheck(glVertex3dProcPtr, __VA_ARGS__)
#define _glVertex3dv(...) callWithGLCheck(glVertex3dv, __VA_ARGS__)
#define _glVertex3dvProcPtr(...) \
    callWithGLCheck(glVertex3dvProcPtr, __VA_ARGS__)
#define _glVertex3f(...) callWithGLCheck(glVertex3f, __VA_ARGS__)
#define _glVertex3fProcPtr(...) callWithGLCheck(glVertex3fProcPtr, __VA_ARGS__)
#define _glVertex3fv(...) callWithGLCheck(glVertex3fv, __VA_ARGS__)
#define _glVertex3fvProcPtr(...) \
    callWithGLCheck(glVertex3fvProcPtr, __VA_ARGS__)
#define _glVertex3i(...) callWithGLCheck(glVertex3i, __VA_ARGS__)
#define _glVertex3iProcPtr(...) callWithGLCheck(glVertex3iProcPtr, __VA_ARGS__)
#define _glVertex3iv(...) callWithGLCheck(glVertex3iv, __VA_ARGS__)
#define _glVertex3ivProcPtr(...) \
    callWithGLCheck(glVertex3ivProcPtr, __VA_ARGS__)
#define _glVertex3s(...) callWithGLCheck(glVertex3s, __VA_ARGS__)
#define _glVertex3sProcPtr(...) callWithGLCheck(glVertex3sProcPtr, __VA_ARGS__)
#define _glVertex3sv(...) callWithGLCheck(glVertex3sv, __VA_ARGS__)
#define _glVertex3svProcPtr(...) \
    callWithGLCheck(glVertex3svProcPtr, __VA_ARGS__)
#define _glVertex4d(...) callWithGLCheck(glVertex4d, __VA_ARGS__)
#define _glVertex4dProcPtr(...) callWithGLCheck(glVertex4dProcPtr, __VA_ARGS__)
#define _glVertex4dv(...) callWithGLCheck(glVertex4dv, __VA_ARGS__)
#define _glVertex4dvProcPtr(...) \
    callWithGLCheck(glVertex4dvProcPtr, __VA_ARGS__)
#define _glVertex4f(...) callWithGLCheck(glVertex4f, __VA_ARGS__)
#define _glVertex4fProcPtr(...) callWithGLCheck(glVertex4fProcPtr, __VA_ARGS__)
#define _glVertex4fv(...) callWithGLCheck(glVertex4fv, __VA_ARGS__)
#define _glVertex4fvProcPtr(...) \
    callWithGLCheck(glVertex4fvProcPtr, __VA_ARGS__)
#define _glVertex4i(...) callWithGLCheck(glVertex4i, __VA_ARGS__)
#define _glVertex4iProcPtr(...) callWithGLCheck(glVertex4iProcPtr, __VA_ARGS__)
#define _glVertex4iv(...) callWithGLCheck(glVertex4iv, __VA_ARGS__)
#define _glVertex4ivProcPtr(...) \
    callWithGLCheck(glVertex4ivProcPtr, __VA_ARGS__)
#define _glVertex4s(...) callWithGLCheck(glVertex4s, __VA_ARGS__)
#define _glVertex4sProcPtr(...) callWithGLCheck(glVertex4sProcPtr, __VA_ARGS__)
#define _glVertex4sv(...) callWithGLCheck(glVertex4sv, __VA_ARGS__)
#define _glVertex4svProcPtr(...) \
    callWithGLCheck(glVertex4svProcPtr, __VA_ARGS__)
#define _glVertexAttrib1d(...) callWithGLCheck(glVertexAttrib1d, __VA_ARGS__)
#define _glVertexAttrib1dProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dProcPtr, __VA_ARGS__)
#define _glVertexAttrib1dv(...) callWithGLCheck(glVertexAttrib1dv, __VA_ARGS__)
#define _glVertexAttrib1dvProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dvProcPtr, __VA_ARGS__)
#define _glVertexAttrib1f(...) callWithGLCheck(glVertexAttrib1f, __VA_ARGS__)
#define _glVertexAttrib1fProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fProcPtr, __VA_ARGS__)
#define _glVertexAttrib1fv(...) callWithGLCheck(glVertexAttrib1fv, __VA_ARGS__)
#define _glVertexAttrib1fvProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fvProcPtr, __VA_ARGS__)
#define _glVertexAttrib1s(...) callWithGLCheck(glVertexAttrib1s, __VA_ARGS__)
#define _glVertexAttrib1sProcPtr(...) \
    callWithGLCheck(glVertexAttrib1sProcPtr, __VA_ARGS__)
#define _glVertexAttrib1sv(...) callWithGLCheck(glVertexAttrib1sv, __VA_ARGS__)
#define _glVertexAttrib1svProcPtr(...) \
    callWithGLCheck(glVertexAttrib1svProcPtr, __VA_ARGS__)
#define _glVertexAttrib2d(...) callWithGLCheck(glVertexAttrib2d, __VA_ARGS__)
#define _glVertexAttrib2dProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dProcPtr, __VA_ARGS__)
#define _glVertexAttrib2dv(...) callWithGLCheck(glVertexAttrib2dv, __VA_ARGS__)
#define _glVertexAttrib2dvProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dvProcPtr, __VA_ARGS__)
#define _glVertexAttrib2f(...) callWithGLCheck(glVertexAttrib2f, __VA_ARGS__)
#define _glVertexAttrib2fProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fProcPtr, __VA_ARGS__)
#define _glVertexAttrib2fv(...) callWithGLCheck(glVertexAttrib2fv, __VA_ARGS__)
#define _glVertexAttrib2fvProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fvProcPtr, __VA_ARGS__)
#define _glVertexAttrib2s(...) callWithGLCheck(glVertexAttrib2s, __VA_ARGS__)
#define _glVertexAttrib2sProcPtr(...) \
    callWithGLCheck(glVertexAttrib2sProcPtr, __VA_ARGS__)
#define _glVertexAttrib2sv(...) callWithGLCheck(glVertexAttrib2sv, __VA_ARGS__)
#define _glVertexAttrib2svProcPtr(...) \
    callWithGLCheck(glVertexAttrib2svProcPtr, __VA_ARGS__)
#define _glVertexAttrib3d(...) callWithGLCheck(glVertexAttrib3d, __VA_ARGS__)
#define _glVertexAttrib3dProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dProcPtr, __VA_ARGS__)
#define _glVertexAttrib3dv(...) callWithGLCheck(glVertexAttrib3dv, __VA_ARGS__)
#define _glVertexAttrib3dvProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dvProcPtr, __VA_ARGS__)
#define _glVertexAttrib3f(...) callWithGLCheck(glVertexAttrib3f, __VA_ARGS__)
#define _glVertexAttrib3fProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fProcPtr, __VA_ARGS__)
#define _glVertexAttrib3fv(...) callWithGLCheck(glVertexAttrib3fv, __VA_ARGS__)
#define _glVertexAttrib3fvProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fvProcPtr, __VA_ARGS__)
#define _glVertexAttrib3s(...) callWithGLCheck(glVertexAttrib3s, __VA_ARGS__)
#define _glVertexAttrib3sProcPtr(...) \
    callWithGLCheck(glVertexAttrib3sProcPtr, __VA_ARGS__)
#define _glVertexAttrib3sv(...) callWithGLCheck(glVertexAttrib3sv, __VA_ARGS__)
#define _glVertexAttrib3svProcPtr(...) \
    callWithGLCheck(glVertexAttrib3svProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nbv(...) \
    callWithGLCheck(glVertexAttrib4Nbv, __VA_ARGS__)
#define _glVertexAttrib4NbvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NbvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Niv(...) \
    callWithGLCheck(glVertexAttrib4Niv, __VA_ARGS__)
#define _glVertexAttrib4NivProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NivProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nsv(...) \
    callWithGLCheck(glVertexAttrib4Nsv, __VA_ARGS__)
#define _glVertexAttrib4NsvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NsvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nub(...) \
    callWithGLCheck(glVertexAttrib4Nub, __VA_ARGS__)
#define _glVertexAttrib4NubProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NubProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nubv(...) \
    callWithGLCheck(glVertexAttrib4Nubv, __VA_ARGS__)
#define _glVertexAttrib4NubvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NubvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nuiv(...) \
    callWithGLCheck(glVertexAttrib4Nuiv, __VA_ARGS__)
#define _glVertexAttrib4NuivProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NuivProcPtr, __VA_ARGS__)
#define _glVertexAttrib4Nusv(...) \
    callWithGLCheck(glVertexAttrib4Nusv, __VA_ARGS__)
#define _glVertexAttrib4NusvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NusvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4bv(...) callWithGLCheck(glVertexAttrib4bv, __VA_ARGS__)
#define _glVertexAttrib4bvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4bvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4d(...) callWithGLCheck(glVertexAttrib4d, __VA_ARGS__)
#define _glVertexAttrib4dProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dProcPtr, __VA_ARGS__)
#define _glVertexAttrib4dv(...) callWithGLCheck(glVertexAttrib4dv, __VA_ARGS__)
#define _glVertexAttrib4dvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4f(...) callWithGLCheck(glVertexAttrib4f, __VA_ARGS__)
#define _glVertexAttrib4fProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fProcPtr, __VA_ARGS__)
#define _glVertexAttrib4fv(...) callWithGLCheck(glVertexAttrib4fv, __VA_ARGS__)
#define _glVertexAttrib4fvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4iv(...) callWithGLCheck(glVertexAttrib4iv, __VA_ARGS__)
#define _glVertexAttrib4ivProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ivProcPtr, __VA_ARGS__)
#define _glVertexAttrib4s(...) callWithGLCheck(glVertexAttrib4s, __VA_ARGS__)
#define _glVertexAttrib4sProcPtr(...) \
    callWithGLCheck(glVertexAttrib4sProcPtr, __VA_ARGS__)
#define _glVertexAttrib4sv(...) callWithGLCheck(glVertexAttrib4sv, __VA_ARGS__)
#define _glVertexAttrib4svProcPtr(...) \
    callWithGLCheck(glVertexAttrib4svProcPtr, __VA_ARGS__)
#define _glVertexAttrib4ubv(...) \
    callWithGLCheck(glVertexAttrib4ubv, __VA_ARGS__)
#define _glVertexAttrib4ubvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ubvProcPtr, __VA_ARGS__)
#define _glVertexAttrib4uiv(...) \
    callWithGLCheck(glVertexAttrib4uiv, __VA_ARGS__)
#define _glVertexAttrib4uivProcPtr(...) \
    callWithGLCheck(glVertexAttrib4uivProcPtr, __VA_ARGS__)
#define _glVertexAttrib4usv(...) \
    callWithGLCheck(glVertexAttrib4usv, __VA_ARGS__)
#define _glVertexAttrib4usvProcPtr(...) \
    callWithGLCheck(glVertexAttrib4usvProcPtr, __VA_ARGS__)
#define _glVertexAttribPointer(...) \
    callWithGLCheck(glVertexAttribPointer, __VA_ARGS__)
#define _glVertexAttribPointerProcPtr(...) \
    callWithGLCheck(glVertexAttribPointerProcPtr, __VA_ARGS__)
#define _glVertexPointer(...) callWithGLCheck(glVertexPointer, __VA_ARGS__)
#define _glVertexPointerProcPtr(...) \
    callWithGLCheck(glVertexPointerProcPtr, __VA_ARGS__)
#define _glViewport(...) callWithGLCheck(glViewport, __VA_ARGS__)
#define _glViewportProcPtr(...) callWithGLCheck(glViewportProcPtr, __VA_ARGS__)
#define _glWindowPos2d(...) callWithGLCheck(glWindowPos2d, __VA_ARGS__)
#define _glWindowPos2dProcPtr(...) \
    callWithGLCheck(glWindowPos2dProcPtr, __VA_ARGS__)
#define _glWindowPos2dv(...) callWithGLCheck(glWindowPos2dv, __VA_ARGS__)
#define _glWindowPos2dvProcPtr(...) \
    callWithGLCheck(glWindowPos2dvProcPtr, __VA_ARGS__)
#define _glWindowPos2f(...) callWithGLCheck(glWindowPos2f, __VA_ARGS__)
#define _glWindowPos2fProcPtr(...) \
    callWithGLCheck(glWindowPos2fProcPtr, __VA_ARGS__)
#define _glWindowPos2fv(...) callWithGLCheck(glWindowPos2fv, __VA_ARGS__)
#define _glWindowPos2fvProcPtr(...) \
    callWithGLCheck(glWindowPos2fvProcPtr, __VA_ARGS__)
#define _glWindowPos2i(...) callWithGLCheck(glWindowPos2i, __VA_ARGS__)
#define _glWindowPos2iProcPtr(...) \
    callWithGLCheck(glWindowPos2iProcPtr, __VA_ARGS__)
#define _glWindowPos2iv(...) callWithGLCheck(glWindowPos2iv, __VA_ARGS__)
#define _glWindowPos2ivProcPtr(...) \
    callWithGLCheck(glWindowPos2ivProcPtr, __VA_ARGS__)
#define _glWindowPos2s(...) callWithGLCheck(glWindowPos2s, __VA_ARGS__)
#define _glWindowPos2sProcPtr(...) \
    callWithGLCheck(glWindowPos2sProcPtr, __VA_ARGS__)
#define _glWindowPos2sv(...) callWithGLCheck(glWindowPos2sv, __VA_ARGS__)
#define _glWindowPos2svProcPtr(...) \
    callWithGLCheck(glWindowPos2svProcPtr, __VA_ARGS__)
#define _glWindowPos3d(...) callWithGLCheck(glWindowPos3d, __VA_ARGS__)
#define _glWindowPos3dProcPtr(...) \
    callWithGLCheck(glWindowPos3dProcPtr, __VA_ARGS__)
#define _glWindowPos3dv(...) callWithGLCheck(glWindowPos3dv, __VA_ARGS__)
#define _glWindowPos3dvProcPtr(...) \
    callWithGLCheck(glWindowPos3dvProcPtr, __VA_ARGS__)
#define _glWindowPos3f(...) callWithGLCheck(glWindowPos3f, __VA_ARGS__)
#define _glWindowPos3fProcPtr(...) \
    callWithGLCheck(glWindowPos3fProcPtr, __VA_ARGS__)
#define _glWindowPos3fv(...) callWithGLCheck(glWindowPos3fv, __VA_ARGS__)
#define _glWindowPos3fvProcPtr(...) \
    callWithGLCheck(glWindowPos3fvProcPtr, __VA_ARGS__)
#define _glWindowPos3i(...) callWithGLCheck(glWindowPos3i, __VA_ARGS__)
#define _glWindowPos3iProcPtr(...) \
    callWithGLCheck(glWindowPos3iProcPtr, __VA_ARGS__)
#define _glWindowPos3iv(...) callWithGLCheck(glWindowPos3iv, __VA_ARGS__)
#define _glWindowPos3ivProcPtr(...) \
    callWithGLCheck(glWindowPos3ivProcPtr, __VA_ARGS__)
#define _glWindowPos3s(...) callWithGLCheck(glWindowPos3s, __VA_ARGS__)
#define _glWindowPos3sProcPtr(...) \
    callWithGLCheck(glWindowPos3sProcPtr, __VA_ARGS__)
#define _glWindowPos3sv(...) callWithGLCheck(glWindowPos3sv, __VA_ARGS__)
#define _glWindowPos3svProcPtr(...) \
    callWithGLCheck(glWindowPos3svProcPtr, __VA_ARGS__)
#define _glActiveShaderProgram(...) \
    callWithGLCheck(glActiveShaderProgram, __VA_ARGS__)
#define _glActiveTexture(...) callWithGLCheck(glActiveTexture, __VA_ARGS__)
#define _glAttachShader(...) callWithGLCheck(glAttachShader, __VA_ARGS__)
#define _glBeginConditionalRender(...) \
    callWithGLCheck(glBeginConditionalRender, __VA_ARGS__)
#define _glBeginQuery(...) callWithGLCheck(glBeginQuery, __VA_ARGS__)
#define _glBeginQueryIndexed(...) \
    callWithGLCheck(glBeginQueryIndexed, __VA_ARGS__)
#define _glBeginTransformFeedback(...) \
    callWithGLCheck(glBeginTransformFeedback, __VA_ARGS__)
#define _glBindAttribLocation(...) \
    callWithGLCheck(glBindAttribLocation, __VA_ARGS__)
#define _glBindBuffer(...) callWithGLCheck(glBindBuffer, __VA_ARGS__)
#define _glBindBufferBase(...) callWithGLCheck(glBindBufferBase, __VA_ARGS__)
#define _glBindBufferRange(...) callWithGLCheck(glBindBufferRange, __VA_ARGS__)
#define _glBindFragDataLocation(...) \
    callWithGLCheck(glBindFragDataLocation, __VA_ARGS__)
#define _glBindFragDataLocationIndexed(...) \
    callWithGLCheck(glBindFragDataLocationIndexed, __VA_ARGS__)
#define _glBindFramebuffer(...) callWithGLCheck(glBindFramebuffer, __VA_ARGS__)
#define _glBindProgramPipeline(...) \
    callWithGLCheck(glBindProgramPipeline, __VA_ARGS__)
#define _glBindRenderbuffer(...) \
    callWithGLCheck(glBindRenderbuffer, __VA_ARGS__)
#define _glBindSampler(...) callWithGLCheck(glBindSampler, __VA_ARGS__)
#define _glBindTexture(...) callWithGLCheck(glBindTexture, __VA_ARGS__)
#define _glBindTransformFeedback(...) \
    callWithGLCheck(glBindTransformFeedback, __VA_ARGS__)
#define _glBindVertexArray(...) callWithGLCheck(glBindVertexArray, __VA_ARGS__)
#define _glBlendColor(...) callWithGLCheck(glBlendColor, __VA_ARGS__)
#define _glBlendEquation(...) callWithGLCheck(glBlendEquation, __VA_ARGS__)
#define _glBlendEquationSeparate(...) \
    callWithGLCheck(glBlendEquationSeparate, __VA_ARGS__)
#define _glBlendEquationSeparatei(...) \
    callWithGLCheck(glBlendEquationSeparatei, __VA_ARGS__)
#define _glBlendEquationi(...) callWithGLCheck(glBlendEquationi, __VA_ARGS__)
#define _glBlendFunc(...) callWithGLCheck(glBlendFunc, __VA_ARGS__)
#define _glBlendFuncSeparate(...) \
    callWithGLCheck(glBlendFuncSeparate, __VA_ARGS__)
#define _glBlendFuncSeparatei(...) \
    callWithGLCheck(glBlendFuncSeparatei, __VA_ARGS__)
#define _glBlendFunci(...) callWithGLCheck(glBlendFunci, __VA_ARGS__)
#define _glBlitFramebuffer(...) callWithGLCheck(glBlitFramebuffer, __VA_ARGS__)
#define _glBufferData(...) callWithGLCheck(glBufferData, __VA_ARGS__)
#define _glBufferSubData(...) callWithGLCheck(glBufferSubData, __VA_ARGS__)
#define _glCheckFramebufferStatus(...) \
    callWithGLCheck(glCheckFramebufferStatus, __VA_ARGS__)
#define _glClampColor(...) callWithGLCheck(glClampColor, __VA_ARGS__)
#define _glClear(...) callWithGLCheck(glClear, __VA_ARGS__)
#define _glClearBufferfi(...) callWithGLCheck(glClearBufferfi, __VA_ARGS__)
#define _glClearBufferfv(...) callWithGLCheck(glClearBufferfv, __VA_ARGS__)
#define _glClearBufferiv(...) callWithGLCheck(glClearBufferiv, __VA_ARGS__)
#define _glClearBufferuiv(...) callWithGLCheck(glClearBufferuiv, __VA_ARGS__)
#define _glClearColor(...) callWithGLCheck(glClearColor, __VA_ARGS__)
#define _glClearDepth(...) callWithGLCheck(glClearDepth, __VA_ARGS__)
#define _glClearDepthf(...) callWithGLCheck(glClearDepthf, __VA_ARGS__)
#define _glClearStencil(...) callWithGLCheck(glClearStencil, __VA_ARGS__)
#define _glClientWaitSync(...) callWithGLCheck(glClientWaitSync, __VA_ARGS__)
#define _glColorMask(...) callWithGLCheck(glColorMask, __VA_ARGS__)
#define _glColorMaski(...) callWithGLCheck(glColorMaski, __VA_ARGS__)
#define _glCompileShader(...) callWithGLCheck(glCompileShader, __VA_ARGS__)
#define _glCompressedTexImage1D(...) \
    callWithGLCheck(glCompressedTexImage1D, __VA_ARGS__)
#define _glCompressedTexImage2D(...) \
    callWithGLCheck(glCompressedTexImage2D, __VA_ARGS__)
#define _glCompressedTexImage3D(...) \
    callWithGLCheck(glCompressedTexImage3D, __VA_ARGS__)
#define _glCompressedTexSubImage1D(...) \
    callWithGLCheck(glCompressedTexSubImage1D, __VA_ARGS__)
#define _glCompressedTexSubImage2D(...) \
    callWithGLCheck(glCompressedTexSubImage2D, __VA_ARGS__)
#define _glCompressedTexSubImage3D(...) \
    callWithGLCheck(glCompressedTexSubImage3D, __VA_ARGS__)
#define _glCopyBufferSubData(...) \
    callWithGLCheck(glCopyBufferSubData, __VA_ARGS__)
#define _glCopyTexImage1D(...) callWithGLCheck(glCopyTexImage1D, __VA_ARGS__)
#define _glCopyTexImage2D(...) callWithGLCheck(glCopyTexImage2D, __VA_ARGS__)
#define _glCopyTexSubImage1D(...) \
    callWithGLCheck(glCopyTexSubImage1D, __VA_ARGS__)
#define _glCopyTexSubImage2D(...) \
    callWithGLCheck(glCopyTexSubImage2D, __VA_ARGS__)
#define _glCopyTexSubImage3D(...) \
    callWithGLCheck(glCopyTexSubImage3D, __VA_ARGS__)
#define _glCreateProgram(...) callWithGLCheck(glCreateProgram, __VA_ARGS__)
#define _glCreateShader(...) callWithGLCheck(glCreateShader, __VA_ARGS__)
#define _glCreateShaderProgramv(...) \
    callWithGLCheck(glCreateShaderProgramv, __VA_ARGS__)
#define _glCullFace(...) callWithGLCheck(glCullFace, __VA_ARGS__)
#define _glDeleteBuffers(...) callWithGLCheck(glDeleteBuffers, __VA_ARGS__)
#define _glDeleteFramebuffers(...) \
    callWithGLCheck(glDeleteFramebuffers, __VA_ARGS__)
#define _glDeleteProgram(...) callWithGLCheck(glDeleteProgram, __VA_ARGS__)
#define _glDeleteProgramPipelines(...) \
    callWithGLCheck(glDeleteProgramPipelines, __VA_ARGS__)
#define _glDeleteQueries(...) callWithGLCheck(glDeleteQueries, __VA_ARGS__)
#define _glDeleteRenderbuffers(...) \
    callWithGLCheck(glDeleteRenderbuffers, __VA_ARGS__)
#define _glDeleteSamplers(...) callWithGLCheck(glDeleteSamplers, __VA_ARGS__)
#define _glDeleteShader(...) callWithGLCheck(glDeleteShader, __VA_ARGS__)
#define _glDeleteSync(...) callWithGLCheck(glDeleteSync, __VA_ARGS__)
#define _glDeleteTextures(...) callWithGLCheck(glDeleteTextures, __VA_ARGS__)
#define _glDeleteTransformFeedbacks(...) \
    callWithGLCheck(glDeleteTransformFeedbacks, __VA_ARGS__)
#define _glDeleteVertexArrays(...) \
    callWithGLCheck(glDeleteVertexArrays, __VA_ARGS__)
#define _glDepthFunc(...) callWithGLCheck(glDepthFunc, __VA_ARGS__)
#define _glDepthMask(...) callWithGLCheck(glDepthMask, __VA_ARGS__)
#define _glDepthRange(...) callWithGLCheck(glDepthRange, __VA_ARGS__)
#define _glDepthRangeArrayv(...) \
    callWithGLCheck(glDepthRangeArrayv, __VA_ARGS__)
#define _glDepthRangeIndexed(...) \
    callWithGLCheck(glDepthRangeIndexed, __VA_ARGS__)
#define _glDepthRangef(...) callWithGLCheck(glDepthRangef, __VA_ARGS__)
#define _glDetachShader(...) callWithGLCheck(glDetachShader, __VA_ARGS__)
#define _glDisable(...) callWithGLCheck(glDisable, __VA_ARGS__)
#define _glDisableVertexAttribArray(...) \
    callWithGLCheck(glDisableVertexAttribArray, __VA_ARGS__)
#define _glDisablei(...) callWithGLCheck(glDisablei, __VA_ARGS__)
#define _glDrawArrays(...) callWithGLCheck(glDrawArrays, __VA_ARGS__)
#define _glDrawArraysIndirect(...) \
    callWithGLCheck(glDrawArraysIndirect, __VA_ARGS__)
#define _glDrawArraysInstanced(...) \
    callWithGLCheck(glDrawArraysInstanced, __VA_ARGS__)
#define _glDrawBuffer(...) callWithGLCheck(glDrawBuffer, __VA_ARGS__)
#define _glDrawBuffers(...) callWithGLCheck(glDrawBuffers, __VA_ARGS__)
#define _glDrawElements(...) callWithGLCheck(glDrawElements, __VA_ARGS__)
#define _glDrawElementsBaseVertex(...) \
    callWithGLCheck(glDrawElementsBaseVertex, __VA_ARGS__)
#define _glDrawElementsIndirect(...) \
    callWithGLCheck(glDrawElementsIndirect, __VA_ARGS__)
#define _glDrawElementsInstanced(...) \
    callWithGLCheck(glDrawElementsInstanced, __VA_ARGS__)
#define _glDrawElementsInstancedBaseVertex(...) \
    callWithGLCheck(glDrawElementsInstancedBaseVertex, __VA_ARGS__)
#define _glDrawRangeElements(...) \
    callWithGLCheck(glDrawRangeElements, __VA_ARGS__)
#define _glDrawRangeElementsBaseVertex(...) \
    callWithGLCheck(glDrawRangeElementsBaseVertex, __VA_ARGS__)
#define _glDrawTransformFeedback(...) \
    callWithGLCheck(glDrawTransformFeedback, __VA_ARGS__)
#define _glDrawTransformFeedbackStream(...) \
    callWithGLCheck(glDrawTransformFeedbackStream, __VA_ARGS__)
#define _glEnable(...) callWithGLCheck(glEnable, __VA_ARGS__)
#define _glEnableVertexAttribArray(...) \
    callWithGLCheck(glEnableVertexAttribArray, __VA_ARGS__)
#define _glEnablei(...) callWithGLCheck(glEnablei, __VA_ARGS__)
#define _glEndConditionalRender(...) \
    callWithGLCheck(glEndConditionalRender, __VA_ARGS__)
#define _glEndQuery(...) callWithGLCheck(glEndQuery, __VA_ARGS__)
#define _glEndQueryIndexed(...) callWithGLCheck(glEndQueryIndexed, __VA_ARGS__)
#define _glEndTransformFeedback(...) \
    callWithGLCheck(glEndTransformFeedback, __VA_ARGS__)
#define _glFenceSync(...) callWithGLCheck(glFenceSync, __VA_ARGS__)
#define _glFinish(...) callWithGLCheck(glFinish, __VA_ARGS__)
#define _glFlush(...) callWithGLCheck(glFlush, __VA_ARGS__)
#define _glFlushMappedBufferRange(...) \
    callWithGLCheck(glFlushMappedBufferRange, __VA_ARGS__)
#define _glFramebufferRenderbuffer(...) \
    callWithGLCheck(glFramebufferRenderbuffer, __VA_ARGS__)
#define _glFramebufferTexture(...) \
    callWithGLCheck(glFramebufferTexture, __VA_ARGS__)
#define _glFramebufferTexture1D(...) \
    callWithGLCheck(glFramebufferTexture1D, __VA_ARGS__)
#define _glFramebufferTexture2D(...) \
    callWithGLCheck(glFramebufferTexture2D, __VA_ARGS__)
#define _glFramebufferTexture3D(...) \
    callWithGLCheck(glFramebufferTexture3D, __VA_ARGS__)
#define _glFramebufferTextureLayer(...) \
    callWithGLCheck(glFramebufferTextureLayer, __VA_ARGS__)
#define _glFrontFace(...) callWithGLCheck(glFrontFace, __VA_ARGS__)
#define _glGenBuffers(...) callWithGLCheck(glGenBuffers, __VA_ARGS__)
#define _glGenFramebuffers(...) callWithGLCheck(glGenFramebuffers, __VA_ARGS__)
#define _glGenProgramPipelines(...) \
    callWithGLCheck(glGenProgramPipelines, __VA_ARGS__)
#define _glGenQueries(...) callWithGLCheck(glGenQueries, __VA_ARGS__)
#define _glGenRenderbuffers(...) \
    callWithGLCheck(glGenRenderbuffers, __VA_ARGS__)
#define _glGenSamplers(...) callWithGLCheck(glGenSamplers, __VA_ARGS__)
#define _glGenTextures(...) callWithGLCheck(glGenTextures, __VA_ARGS__)
#define _glGenTransformFeedbacks(...) \
    callWithGLCheck(glGenTransformFeedbacks, __VA_ARGS__)
#define _glGenVertexArrays(...) callWithGLCheck(glGenVertexArrays, __VA_ARGS__)
#define _glGenerateMipmap(...) callWithGLCheck(glGenerateMipmap, __VA_ARGS__)
#define _glGetActiveAttrib(...) callWithGLCheck(glGetActiveAttrib, __VA_ARGS__)
#define _glGetActiveSubroutineName(...) \
    callWithGLCheck(glGetActiveSubroutineName, __VA_ARGS__)
#define _glGetActiveSubroutineUniformName(...) \
    callWithGLCheck(glGetActiveSubroutineUniformName, __VA_ARGS__)
#define _glGetActiveSubroutineUniformiv(...) \
    callWithGLCheck(glGetActiveSubroutineUniformiv, __VA_ARGS__)
#define _glGetActiveUniform(...) \
    callWithGLCheck(glGetActiveUniform, __VA_ARGS__)
#define _glGetActiveUniformBlockName(...) \
    callWithGLCheck(glGetActiveUniformBlockName, __VA_ARGS__)
#define _glGetActiveUniformBlockiv(...) \
    callWithGLCheck(glGetActiveUniformBlockiv, __VA_ARGS__)
#define _glGetActiveUniformName(...) \
    callWithGLCheck(glGetActiveUniformName, __VA_ARGS__)
#define _glGetActiveUniformsiv(...) \
    callWithGLCheck(glGetActiveUniformsiv, __VA_ARGS__)
#define _glGetAttachedShaders(...) \
    callWithGLCheck(glGetAttachedShaders, __VA_ARGS__)
#define _glGetAttribLocation(...) \
    callWithGLCheck(glGetAttribLocation, __VA_ARGS__)
#define _glGetBooleani_v(...) callWithGLCheck(glGetBooleani_v, __VA_ARGS__)
#define _glGetBooleanv(...) callWithGLCheck(glGetBooleanv, __VA_ARGS__)
#define _glGetBufferParameteri64v(...) \
    callWithGLCheck(glGetBufferParameteri64v, __VA_ARGS__)
#define _glGetBufferParameteriv(...) \
    callWithGLCheck(glGetBufferParameteriv, __VA_ARGS__)
#define _glGetBufferPointerv(...) \
    callWithGLCheck(glGetBufferPointerv, __VA_ARGS__)
#define _glGetBufferSubData(...) \
    callWithGLCheck(glGetBufferSubData, __VA_ARGS__)
#define _glGetCompressedTexImage(...) \
    callWithGLCheck(glGetCompressedTexImage, __VA_ARGS__)
#define _glGetDoublei_v(...) callWithGLCheck(glGetDoublei_v, __VA_ARGS__)
#define _glGetDoublev(...) callWithGLCheck(glGetDoublev, __VA_ARGS__)
#define _glGetError(...) callWithGLCheck(glGetError, __VA_ARGS__)
#define _glGetFloati_v(...) callWithGLCheck(glGetFloati_v, __VA_ARGS__)
#define _glGetFloatv(...) callWithGLCheck(glGetFloatv, __VA_ARGS__)
#define _glGetFragDataIndex(...) \
    callWithGLCheck(glGetFragDataIndex, __VA_ARGS__)
#define _glGetFragDataLocation(...) \
    callWithGLCheck(glGetFragDataLocation, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameteriv(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameteriv, __VA_ARGS__)
#define _glGetInteger64i_v(...) callWithGLCheck(glGetInteger64i_v, __VA_ARGS__)
#define _glGetInteger64v(...) callWithGLCheck(glGetInteger64v, __VA_ARGS__)
#define _glGetIntegeri_v(...) callWithGLCheck(glGetIntegeri_v, __VA_ARGS__)
#define _glGetIntegerv(...) callWithGLCheck(glGetIntegerv, __VA_ARGS__)
#define _glGetMultisamplefv(...) \
    callWithGLCheck(glGetMultisamplefv, __VA_ARGS__)
#define _glGetProgramBinary(...) \
    callWithGLCheck(glGetProgramBinary, __VA_ARGS__)
#define _glGetProgramInfoLog(...) \
    callWithGLCheck(glGetProgramInfoLog, __VA_ARGS__)
#define _glGetProgramPipelineInfoLog(...) \
    callWithGLCheck(glGetProgramPipelineInfoLog, __VA_ARGS__)
#define _glGetProgramPipelineiv(...) \
    callWithGLCheck(glGetProgramPipelineiv, __VA_ARGS__)
#define _glGetProgramStageiv(...) \
    callWithGLCheck(glGetProgramStageiv, __VA_ARGS__)
#define _glGetProgramiv(...) callWithGLCheck(glGetProgramiv, __VA_ARGS__)
#define _glGetQueryIndexediv(...) \
    callWithGLCheck(glGetQueryIndexediv, __VA_ARGS__)
#define _glGetQueryObjecti64v(...) \
    callWithGLCheck(glGetQueryObjecti64v, __VA_ARGS__)
#define _glGetQueryObjectiv(...) \
    callWithGLCheck(glGetQueryObjectiv, __VA_ARGS__)
#define _glGetQueryObjectui64v(...) \
    callWithGLCheck(glGetQueryObjectui64v, __VA_ARGS__)
#define _glGetQueryObjectuiv(...) \
    callWithGLCheck(glGetQueryObjectuiv, __VA_ARGS__)
#define _glGetQueryiv(...) callWithGLCheck(glGetQueryiv, __VA_ARGS__)
#define _glGetRenderbufferParameteriv(...) \
    callWithGLCheck(glGetRenderbufferParameteriv, __VA_ARGS__)
#define _glGetSamplerParameterIiv(...) \
    callWithGLCheck(glGetSamplerParameterIiv, __VA_ARGS__)
#define _glGetSamplerParameterIuiv(...) \
    callWithGLCheck(glGetSamplerParameterIuiv, __VA_ARGS__)
#define _glGetSamplerParameterfv(...) \
    callWithGLCheck(glGetSamplerParameterfv, __VA_ARGS__)
#define _glGetSamplerParameteriv(...) \
    callWithGLCheck(glGetSamplerParameteriv, __VA_ARGS__)
#define _glGetShaderInfoLog(...) \
    callWithGLCheck(glGetShaderInfoLog, __VA_ARGS__)
#define _glGetShaderPrecisionFormat(...) \
    callWithGLCheck(glGetShaderPrecisionFormat, __VA_ARGS__)
#define _glGetShaderSource(...) callWithGLCheck(glGetShaderSource, __VA_ARGS__)
#define _glGetShaderiv(...) callWithGLCheck(glGetShaderiv, __VA_ARGS__)
#define _glGetString(...) callWithGLCheck(glGetString, __VA_ARGS__)
#define _glGetStringi(...) callWithGLCheck(glGetStringi, __VA_ARGS__)
#define _glGetSubroutineIndex(...) \
    callWithGLCheck(glGetSubroutineIndex, __VA_ARGS__)
#define _glGetSubroutineUniformLocation(...) \
    callWithGLCheck(glGetSubroutineUniformLocation, __VA_ARGS__)
#define _glGetSynciv(...) callWithGLCheck(glGetSynciv, __VA_ARGS__)
#define _glGetTexImage(...) callWithGLCheck(glGetTexImage, __VA_ARGS__)
#define _glGetTexLevelParameterfv(...) \
    callWithGLCheck(glGetTexLevelParameterfv, __VA_ARGS__)
#define _glGetTexLevelParameteriv(...) \
    callWithGLCheck(glGetTexLevelParameteriv, __VA_ARGS__)
#define _glGetTexParameterIiv(...) \
    callWithGLCheck(glGetTexParameterIiv, __VA_ARGS__)
#define _glGetTexParameterIuiv(...) \
    callWithGLCheck(glGetTexParameterIuiv, __VA_ARGS__)
#define _glGetTexParameterfv(...) \
    callWithGLCheck(glGetTexParameterfv, __VA_ARGS__)
#define _glGetTexParameteriv(...) \
    callWithGLCheck(glGetTexParameteriv, __VA_ARGS__)
#define _glGetTransformFeedbackVarying(...) \
    callWithGLCheck(glGetTransformFeedbackVarying, __VA_ARGS__)
#define _glGetUniformBlockIndex(...) \
    callWithGLCheck(glGetUniformBlockIndex, __VA_ARGS__)
#define _glGetUniformIndices(...) \
    callWithGLCheck(glGetUniformIndices, __VA_ARGS__)
#define _glGetUniformLocation(...) \
    callWithGLCheck(glGetUniformLocation, __VA_ARGS__)
#define _glGetUniformSubroutineuiv(...) \
    callWithGLCheck(glGetUniformSubroutineuiv, __VA_ARGS__)
#define _glGetUniformdv(...) callWithGLCheck(glGetUniformdv, __VA_ARGS__)
#define _glGetUniformfv(...) callWithGLCheck(glGetUniformfv, __VA_ARGS__)
#define _glGetUniformiv(...) callWithGLCheck(glGetUniformiv, __VA_ARGS__)
#define _glGetUniformuiv(...) callWithGLCheck(glGetUniformuiv, __VA_ARGS__)
#define _glGetVertexAttribIiv(...) \
    callWithGLCheck(glGetVertexAttribIiv, __VA_ARGS__)
#define _glGetVertexAttribIuiv(...) \
    callWithGLCheck(glGetVertexAttribIuiv, __VA_ARGS__)
#define _glGetVertexAttribLdv(...) \
    callWithGLCheck(glGetVertexAttribLdv, __VA_ARGS__)
#define _glGetVertexAttribPointerv(...) \
    callWithGLCheck(glGetVertexAttribPointerv, __VA_ARGS__)
#define _glGetVertexAttribdv(...) \
    callWithGLCheck(glGetVertexAttribdv, __VA_ARGS__)
#define _glGetVertexAttribfv(...) \
    callWithGLCheck(glGetVertexAttribfv, __VA_ARGS__)
#define _glGetVertexAttribiv(...) \
    callWithGLCheck(glGetVertexAttribiv, __VA_ARGS__)
#define _glHint(...) callWithGLCheck(glHint, __VA_ARGS__)
#define _glIsBuffer(...) callWithGLCheck(glIsBuffer, __VA_ARGS__)
#define _glIsEnabled(...) callWithGLCheck(glIsEnabled, __VA_ARGS__)
#define _glIsEnabledi(...) callWithGLCheck(glIsEnabledi, __VA_ARGS__)
#define _glIsFramebuffer(...) callWithGLCheck(glIsFramebuffer, __VA_ARGS__)
#define _glIsProgram(...) callWithGLCheck(glIsProgram, __VA_ARGS__)
#define _glIsProgramPipeline(...) \
    callWithGLCheck(glIsProgramPipeline, __VA_ARGS__)
#define _glIsQuery(...) callWithGLCheck(glIsQuery, __VA_ARGS__)
#define _glIsRenderbuffer(...) callWithGLCheck(glIsRenderbuffer, __VA_ARGS__)
#define _glIsSampler(...) callWithGLCheck(glIsSampler, __VA_ARGS__)
#define _glIsShader(...) callWithGLCheck(glIsShader, __VA_ARGS__)
#define _glIsSync(...) callWithGLCheck(glIsSync, __VA_ARGS__)
#define _glIsTexture(...) callWithGLCheck(glIsTexture, __VA_ARGS__)
#define _glIsTransformFeedback(...) \
    callWithGLCheck(glIsTransformFeedback, __VA_ARGS__)
#define _glIsVertexArray(...) callWithGLCheck(glIsVertexArray, __VA_ARGS__)
#define _glLineWidth(...) callWithGLCheck(glLineWidth, __VA_ARGS__)
#define _glLinkProgram(...) callWithGLCheck(glLinkProgram, __VA_ARGS__)
#define _glLogicOp(...) callWithGLCheck(glLogicOp, __VA_ARGS__)
#define _glMapBuffer(...) callWithGLCheck(glMapBuffer, __VA_ARGS__)
#define _glMapBufferRange(...) callWithGLCheck(glMapBufferRange, __VA_ARGS__)
#define _glMinSampleShading(...) \
    callWithGLCheck(glMinSampleShading, __VA_ARGS__)
#define _glMultiDrawArrays(...) callWithGLCheck(glMultiDrawArrays, __VA_ARGS__)
#define _glMultiDrawElements(...) \
    callWithGLCheck(glMultiDrawElements, __VA_ARGS__)
#define _glMultiDrawElementsBaseVertex(...) \
    callWithGLCheck(glMultiDrawElementsBaseVertex, __VA_ARGS__)
#define _glPatchParameterfv(...) \
    callWithGLCheck(glPatchParameterfv, __VA_ARGS__)
#define _glPatchParameteri(...) callWithGLCheck(glPatchParameteri, __VA_ARGS__)
#define _glPauseTransformFeedback(...) \
    callWithGLCheck(glPauseTransformFeedback, __VA_ARGS__)
#define _glPixelStoref(...) callWithGLCheck(glPixelStoref, __VA_ARGS__)
#define _glPixelStorei(...) callWithGLCheck(glPixelStorei, __VA_ARGS__)
#define _glPointParameterf(...) callWithGLCheck(glPointParameterf, __VA_ARGS__)
#define _glPointParameterfv(...) \
    callWithGLCheck(glPointParameterfv, __VA_ARGS__)
#define _glPointParameteri(...) callWithGLCheck(glPointParameteri, __VA_ARGS__)
#define _glPointParameteriv(...) \
    callWithGLCheck(glPointParameteriv, __VA_ARGS__)
#define _glPointSize(...) callWithGLCheck(glPointSize, __VA_ARGS__)
#define _glPolygonMode(...) callWithGLCheck(glPolygonMode, __VA_ARGS__)
#define _glPolygonOffset(...) callWithGLCheck(glPolygonOffset, __VA_ARGS__)
#define _glPrimitiveRestartIndex(...) \
    callWithGLCheck(glPrimitiveRestartIndex, __VA_ARGS__)
#define _glProgramBinary(...) callWithGLCheck(glProgramBinary, __VA_ARGS__)
#define _glProgramParameteri(...) \
    callWithGLCheck(glProgramParameteri, __VA_ARGS__)
#define _glProgramUniform1d(...) \
    callWithGLCheck(glProgramUniform1d, __VA_ARGS__)
#define _glProgramUniform1dv(...) \
    callWithGLCheck(glProgramUniform1dv, __VA_ARGS__)
#define _glProgramUniform1f(...) \
    callWithGLCheck(glProgramUniform1f, __VA_ARGS__)
#define _glProgramUniform1fv(...) \
    callWithGLCheck(glProgramUniform1fv, __VA_ARGS__)
#define _glProgramUniform1i(...) \
    callWithGLCheck(glProgramUniform1i, __VA_ARGS__)
#define _glProgramUniform1iv(...) \
    callWithGLCheck(glProgramUniform1iv, __VA_ARGS__)
#define _glProgramUniform1ui(...) \
    callWithGLCheck(glProgramUniform1ui, __VA_ARGS__)
#define _glProgramUniform1uiv(...) \
    callWithGLCheck(glProgramUniform1uiv, __VA_ARGS__)
#define _glProgramUniform2d(...) \
    callWithGLCheck(glProgramUniform2d, __VA_ARGS__)
#define _glProgramUniform2dv(...) \
    callWithGLCheck(glProgramUniform2dv, __VA_ARGS__)
#define _glProgramUniform2f(...) \
    callWithGLCheck(glProgramUniform2f, __VA_ARGS__)
#define _glProgramUniform2fv(...) \
    callWithGLCheck(glProgramUniform2fv, __VA_ARGS__)
#define _glProgramUniform2i(...) \
    callWithGLCheck(glProgramUniform2i, __VA_ARGS__)
#define _glProgramUniform2iv(...) \
    callWithGLCheck(glProgramUniform2iv, __VA_ARGS__)
#define _glProgramUniform2ui(...) \
    callWithGLCheck(glProgramUniform2ui, __VA_ARGS__)
#define _glProgramUniform2uiv(...) \
    callWithGLCheck(glProgramUniform2uiv, __VA_ARGS__)
#define _glProgramUniform3d(...) \
    callWithGLCheck(glProgramUniform3d, __VA_ARGS__)
#define _glProgramUniform3dv(...) \
    callWithGLCheck(glProgramUniform3dv, __VA_ARGS__)
#define _glProgramUniform3f(...) \
    callWithGLCheck(glProgramUniform3f, __VA_ARGS__)
#define _glProgramUniform3fv(...) \
    callWithGLCheck(glProgramUniform3fv, __VA_ARGS__)
#define _glProgramUniform3i(...) \
    callWithGLCheck(glProgramUniform3i, __VA_ARGS__)
#define _glProgramUniform3iv(...) \
    callWithGLCheck(glProgramUniform3iv, __VA_ARGS__)
#define _glProgramUniform3ui(...) \
    callWithGLCheck(glProgramUniform3ui, __VA_ARGS__)
#define _glProgramUniform3uiv(...) \
    callWithGLCheck(glProgramUniform3uiv, __VA_ARGS__)
#define _glProgramUniform4d(...) \
    callWithGLCheck(glProgramUniform4d, __VA_ARGS__)
#define _glProgramUniform4dv(...) \
    callWithGLCheck(glProgramUniform4dv, __VA_ARGS__)
#define _glProgramUniform4f(...) \
    callWithGLCheck(glProgramUniform4f, __VA_ARGS__)
#define _glProgramUniform4fv(...) \
    callWithGLCheck(glProgramUniform4fv, __VA_ARGS__)
#define _glProgramUniform4i(...) \
    callWithGLCheck(glProgramUniform4i, __VA_ARGS__)
#define _glProgramUniform4iv(...) \
    callWithGLCheck(glProgramUniform4iv, __VA_ARGS__)
#define _glProgramUniform4ui(...) \
    callWithGLCheck(glProgramUniform4ui, __VA_ARGS__)
#define _glProgramUniform4uiv(...) \
    callWithGLCheck(glProgramUniform4uiv, __VA_ARGS__)
#define _glProgramUniformMatrix2dv(...) \
    callWithGLCheck(glProgramUniformMatrix2dv, __VA_ARGS__)
#define _glProgramUniformMatrix2fv(...) \
    callWithGLCheck(glProgramUniformMatrix2fv, __VA_ARGS__)
#define _glProgramUniformMatrix2x3dv(...) \
    callWithGLCheck(glProgramUniformMatrix2x3dv, __VA_ARGS__)
#define _glProgramUniformMatrix2x3fv(...) \
    callWithGLCheck(glProgramUniformMatrix2x3fv, __VA_ARGS__)
#define _glProgramUniformMatrix2x4dv(...) \
    callWithGLCheck(glProgramUniformMatrix2x4dv, __VA_ARGS__)
#define _glProgramUniformMatrix2x4fv(...) \
    callWithGLCheck(glProgramUniformMatrix2x4fv, __VA_ARGS__)
#define _glProgramUniformMatrix3dv(...) \
    callWithGLCheck(glProgramUniformMatrix3dv, __VA_ARGS__)
#define _glProgramUniformMatrix3fv(...) \
    callWithGLCheck(glProgramUniformMatrix3fv, __VA_ARGS__)
#define _glProgramUniformMatrix3x2dv(...) \
    callWithGLCheck(glProgramUniformMatrix3x2dv, __VA_ARGS__)
#define _glProgramUniformMatrix3x2fv(...) \
    callWithGLCheck(glProgramUniformMatrix3x2fv, __VA_ARGS__)
#define _glProgramUniformMatrix3x4dv(...) \
    callWithGLCheck(glProgramUniformMatrix3x4dv, __VA_ARGS__)
#define _glProgramUniformMatrix3x4fv(...) \
    callWithGLCheck(glProgramUniformMatrix3x4fv, __VA_ARGS__)
#define _glProgramUniformMatrix4dv(...) \
    callWithGLCheck(glProgramUniformMatrix4dv, __VA_ARGS__)
#define _glProgramUniformMatrix4fv(...) \
    callWithGLCheck(glProgramUniformMatrix4fv, __VA_ARGS__)
#define _glProgramUniformMatrix4x2dv(...) \
    callWithGLCheck(glProgramUniformMatrix4x2dv, __VA_ARGS__)
#define _glProgramUniformMatrix4x2fv(...) \
    callWithGLCheck(glProgramUniformMatrix4x2fv, __VA_ARGS__)
#define _glProgramUniformMatrix4x3dv(...) \
    callWithGLCheck(glProgramUniformMatrix4x3dv, __VA_ARGS__)
#define _glProgramUniformMatrix4x3fv(...) \
    callWithGLCheck(glProgramUniformMatrix4x3fv, __VA_ARGS__)
#define _glProvokingVertex(...) callWithGLCheck(glProvokingVertex, __VA_ARGS__)
#define _glQueryCounter(...) callWithGLCheck(glQueryCounter, __VA_ARGS__)
#define _glReadBuffer(...) callWithGLCheck(glReadBuffer, __VA_ARGS__)
#define _glReadPixels(...) callWithGLCheck(glReadPixels, __VA_ARGS__)
#define _glReleaseShaderCompiler(...) \
    callWithGLCheck(glReleaseShaderCompiler, __VA_ARGS__)
#define _glRenderbufferStorage(...) \
    callWithGLCheck(glRenderbufferStorage, __VA_ARGS__)
#define _glRenderbufferStorageMultisample(...) \
    callWithGLCheck(glRenderbufferStorageMultisample, __VA_ARGS__)
#define _glResumeTransformFeedback(...) \
    callWithGLCheck(glResumeTransformFeedback, __VA_ARGS__)
#define _glSampleCoverage(...) callWithGLCheck(glSampleCoverage, __VA_ARGS__)
#define _glSampleMaski(...) callWithGLCheck(glSampleMaski, __VA_ARGS__)
#define _glSamplerParameterIiv(...) \
    callWithGLCheck(glSamplerParameterIiv, __VA_ARGS__)
#define _glSamplerParameterIuiv(...) \
    callWithGLCheck(glSamplerParameterIuiv, __VA_ARGS__)
#define _glSamplerParameterf(...) \
    callWithGLCheck(glSamplerParameterf, __VA_ARGS__)
#define _glSamplerParameterfv(...) \
    callWithGLCheck(glSamplerParameterfv, __VA_ARGS__)
#define _glSamplerParameteri(...) \
    callWithGLCheck(glSamplerParameteri, __VA_ARGS__)
#define _glSamplerParameteriv(...) \
    callWithGLCheck(glSamplerParameteriv, __VA_ARGS__)
#define _glScissor(...) callWithGLCheck(glScissor, __VA_ARGS__)
#define _glScissorArrayv(...) callWithGLCheck(glScissorArrayv, __VA_ARGS__)
#define _glScissorIndexed(...) callWithGLCheck(glScissorIndexed, __VA_ARGS__)
#define _glScissorIndexedv(...) callWithGLCheck(glScissorIndexedv, __VA_ARGS__)
#define _glShaderBinary(...) callWithGLCheck(glShaderBinary, __VA_ARGS__)
#define _glShaderSource(...) callWithGLCheck(glShaderSource, __VA_ARGS__)
#define _glStencilFunc(...) callWithGLCheck(glStencilFunc, __VA_ARGS__)
#define _glStencilFuncSeparate(...) \
    callWithGLCheck(glStencilFuncSeparate, __VA_ARGS__)
#define _glStencilMask(...) callWithGLCheck(glStencilMask, __VA_ARGS__)
#define _glStencilMaskSeparate(...) \
    callWithGLCheck(glStencilMaskSeparate, __VA_ARGS__)
#define _glStencilOp(...) callWithGLCheck(glStencilOp, __VA_ARGS__)
#define _glStencilOpSeparate(...) \
    callWithGLCheck(glStencilOpSeparate, __VA_ARGS__)
#define _glTexBuffer(...) callWithGLCheck(glTexBuffer, __VA_ARGS__)
#define _glTexImage1D(...) callWithGLCheck(glTexImage1D, __VA_ARGS__)
#define _glTexImage2D(...) callWithGLCheck(glTexImage2D, __VA_ARGS__)
#define _glTexImage2DMultisample(...) \
    callWithGLCheck(glTexImage2DMultisample, __VA_ARGS__)
#define _glTexImage3D(...) callWithGLCheck(glTexImage3D, __VA_ARGS__)
#define _glTexImage3DMultisample(...) \
    callWithGLCheck(glTexImage3DMultisample, __VA_ARGS__)
#define _glTexParameterIiv(...) callWithGLCheck(glTexParameterIiv, __VA_ARGS__)
#define _glTexParameterIuiv(...) \
    callWithGLCheck(glTexParameterIuiv, __VA_ARGS__)
#define _glTexParameterf(...) callWithGLCheck(glTexParameterf, __VA_ARGS__)
#define _glTexParameterfv(...) callWithGLCheck(glTexParameterfv, __VA_ARGS__)
#define _glTexParameteri(...) callWithGLCheck(glTexParameteri, __VA_ARGS__)
#define _glTexParameteriv(...) callWithGLCheck(glTexParameteriv, __VA_ARGS__)
#define _glTexSubImage1D(...) callWithGLCheck(glTexSubImage1D, __VA_ARGS__)
#define _glTexSubImage2D(...) callWithGLCheck(glTexSubImage2D, __VA_ARGS__)
#define _glTexSubImage3D(...) callWithGLCheck(glTexSubImage3D, __VA_ARGS__)
#define _glTransformFeedbackVaryings(...) \
    callWithGLCheck(glTransformFeedbackVaryings, __VA_ARGS__)
#define _glUniform1d(...) callWithGLCheck(glUniform1d, __VA_ARGS__)
#define _glUniform1dv(...) callWithGLCheck(glUniform1dv, __VA_ARGS__)
#define _glUniform1f(...) callWithGLCheck(glUniform1f, __VA_ARGS__)
#define _glUniform1fv(...) callWithGLCheck(glUniform1fv, __VA_ARGS__)
#define _glUniform1i(...) callWithGLCheck(glUniform1i, __VA_ARGS__)
#define _glUniform1iv(...) callWithGLCheck(glUniform1iv, __VA_ARGS__)
#define _glUniform1ui(...) callWithGLCheck(glUniform1ui, __VA_ARGS__)
#define _glUniform1uiv(...) callWithGLCheck(glUniform1uiv, __VA_ARGS__)
#define _glUniform2d(...) callWithGLCheck(glUniform2d, __VA_ARGS__)
#define _glUniform2dv(...) callWithGLCheck(glUniform2dv, __VA_ARGS__)
#define _glUniform2f(...) callWithGLCheck(glUniform2f, __VA_ARGS__)
#define _glUniform2fv(...) callWithGLCheck(glUniform2fv, __VA_ARGS__)
#define _glUniform2i(...) callWithGLCheck(glUniform2i, __VA_ARGS__)
#define _glUniform2iv(...) callWithGLCheck(glUniform2iv, __VA_ARGS__)
#define _glUniform2ui(...) callWithGLCheck(glUniform2ui, __VA_ARGS__)
#define _glUniform2uiv(...) callWithGLCheck(glUniform2uiv, __VA_ARGS__)
#define _glUniform3d(...) callWithGLCheck(glUniform3d, __VA_ARGS__)
#define _glUniform3dv(...) callWithGLCheck(glUniform3dv, __VA_ARGS__)
#define _glUniform3f(...) callWithGLCheck(glUniform3f, __VA_ARGS__)
#define _glUniform3fv(...) callWithGLCheck(glUniform3fv, __VA_ARGS__)
#define _glUniform3i(...) callWithGLCheck(glUniform3i, __VA_ARGS__)
#define _glUniform3iv(...) callWithGLCheck(glUniform3iv, __VA_ARGS__)
#define _glUniform3ui(...) callWithGLCheck(glUniform3ui, __VA_ARGS__)
#define _glUniform3uiv(...) callWithGLCheck(glUniform3uiv, __VA_ARGS__)
#define _glUniform4d(...) callWithGLCheck(glUniform4d, __VA_ARGS__)
#define _glUniform4dv(...) callWithGLCheck(glUniform4dv, __VA_ARGS__)
#define _glUniform4f(...) callWithGLCheck(glUniform4f, __VA_ARGS__)
#define _glUniform4fv(...) callWithGLCheck(glUniform4fv, __VA_ARGS__)
#define _glUniform4i(...) callWithGLCheck(glUniform4i, __VA_ARGS__)
#define _glUniform4iv(...) callWithGLCheck(glUniform4iv, __VA_ARGS__)
#define _glUniform4ui(...) callWithGLCheck(glUniform4ui, __VA_ARGS__)
#define _glUniform4uiv(...) callWithGLCheck(glUniform4uiv, __VA_ARGS__)
#define _glUniformBlockBinding(...) \
    callWithGLCheck(glUniformBlockBinding, __VA_ARGS__)
#define _glUniformMatrix2dv(...) \
    callWithGLCheck(glUniformMatrix2dv, __VA_ARGS__)
#define _glUniformMatrix2fv(...) \
    callWithGLCheck(glUniformMatrix2fv, __VA_ARGS__)
#define _glUniformMatrix2x3dv(...) \
    callWithGLCheck(glUniformMatrix2x3dv, __VA_ARGS__)
#define _glUniformMatrix2x3fv(...) \
    callWithGLCheck(glUniformMatrix2x3fv, __VA_ARGS__)
#define _glUniformMatrix2x4dv(...) \
    callWithGLCheck(glUniformMatrix2x4dv, __VA_ARGS__)
#define _glUniformMatrix2x4fv(...) \
    callWithGLCheck(glUniformMatrix2x4fv, __VA_ARGS__)
#define _glUniformMatrix3dv(...) \
    callWithGLCheck(glUniformMatrix3dv, __VA_ARGS__)
#define _glUniformMatrix3fv(...) \
    callWithGLCheck(glUniformMatrix3fv, __VA_ARGS__)
#define _glUniformMatrix3x2dv(...) \
    callWithGLCheck(glUniformMatrix3x2dv, __VA_ARGS__)
#define _glUniformMatrix3x2fv(...) \
    callWithGLCheck(glUniformMatrix3x2fv, __VA_ARGS__)
#define _glUniformMatrix3x4dv(...) \
    callWithGLCheck(glUniformMatrix3x4dv, __VA_ARGS__)
#define _glUniformMatrix3x4fv(...) \
    callWithGLCheck(glUniformMatrix3x4fv, __VA_ARGS__)
#define _glUniformMatrix4dv(...) \
    callWithGLCheck(glUniformMatrix4dv, __VA_ARGS__)
#define _glUniformMatrix4fv(...) \
    callWithGLCheck(glUniformMatrix4fv, __VA_ARGS__)
#define _glUniformMatrix4x2dv(...) \
    callWithGLCheck(glUniformMatrix4x2dv, __VA_ARGS__)
#define _glUniformMatrix4x2fv(...) \
    callWithGLCheck(glUniformMatrix4x2fv, __VA_ARGS__)
#define _glUniformMatrix4x3dv(...) \
    callWithGLCheck(glUniformMatrix4x3dv, __VA_ARGS__)
#define _glUniformMatrix4x3fv(...) \
    callWithGLCheck(glUniformMatrix4x3fv, __VA_ARGS__)
#define _glUniformSubroutinesuiv(...) \
    callWithGLCheck(glUniformSubroutinesuiv, __VA_ARGS__)
#define _glUnmapBuffer(...) callWithGLCheck(glUnmapBuffer, __VA_ARGS__)
#define _glUseProgram(...) callWithGLCheck(glUseProgram, __VA_ARGS__)
#define _glUseProgramStages(...) \
    callWithGLCheck(glUseProgramStages, __VA_ARGS__)
#define _glValidateProgram(...) callWithGLCheck(glValidateProgram, __VA_ARGS__)
#define _glValidateProgramPipeline(...) \
    callWithGLCheck(glValidateProgramPipeline, __VA_ARGS__)
#define _glVertexAttrib1d(...) callWithGLCheck(glVertexAttrib1d, __VA_ARGS__)
#define _glVertexAttrib1dv(...) callWithGLCheck(glVertexAttrib1dv, __VA_ARGS__)
#define _glVertexAttrib1f(...) callWithGLCheck(glVertexAttrib1f, __VA_ARGS__)
#define _glVertexAttrib1fv(...) callWithGLCheck(glVertexAttrib1fv, __VA_ARGS__)
#define _glVertexAttrib1s(...) callWithGLCheck(glVertexAttrib1s, __VA_ARGS__)
#define _glVertexAttrib1sv(...) callWithGLCheck(glVertexAttrib1sv, __VA_ARGS__)
#define _glVertexAttrib2d(...) callWithGLCheck(glVertexAttrib2d, __VA_ARGS__)
#define _glVertexAttrib2dv(...) callWithGLCheck(glVertexAttrib2dv, __VA_ARGS__)
#define _glVertexAttrib2f(...) callWithGLCheck(glVertexAttrib2f, __VA_ARGS__)
#define _glVertexAttrib2fv(...) callWithGLCheck(glVertexAttrib2fv, __VA_ARGS__)
#define _glVertexAttrib2s(...) callWithGLCheck(glVertexAttrib2s, __VA_ARGS__)
#define _glVertexAttrib2sv(...) callWithGLCheck(glVertexAttrib2sv, __VA_ARGS__)
#define _glVertexAttrib3d(...) callWithGLCheck(glVertexAttrib3d, __VA_ARGS__)
#define _glVertexAttrib3dv(...) callWithGLCheck(glVertexAttrib3dv, __VA_ARGS__)
#define _glVertexAttrib3f(...) callWithGLCheck(glVertexAttrib3f, __VA_ARGS__)
#define _glVertexAttrib3fv(...) callWithGLCheck(glVertexAttrib3fv, __VA_ARGS__)
#define _glVertexAttrib3s(...) callWithGLCheck(glVertexAttrib3s, __VA_ARGS__)
#define _glVertexAttrib3sv(...) callWithGLCheck(glVertexAttrib3sv, __VA_ARGS__)
#define _glVertexAttrib4Nbv(...) \
    callWithGLCheck(glVertexAttrib4Nbv, __VA_ARGS__)
#define _glVertexAttrib4Niv(...) \
    callWithGLCheck(glVertexAttrib4Niv, __VA_ARGS__)
#define _glVertexAttrib4Nsv(...) \
    callWithGLCheck(glVertexAttrib4Nsv, __VA_ARGS__)
#define _glVertexAttrib4Nub(...) \
    callWithGLCheck(glVertexAttrib4Nub, __VA_ARGS__)
#define _glVertexAttrib4Nubv(...) \
    callWithGLCheck(glVertexAttrib4Nubv, __VA_ARGS__)
#define _glVertexAttrib4Nuiv(...) \
    callWithGLCheck(glVertexAttrib4Nuiv, __VA_ARGS__)
#define _glVertexAttrib4Nusv(...) \
    callWithGLCheck(glVertexAttrib4Nusv, __VA_ARGS__)
#define _glVertexAttrib4bv(...) callWithGLCheck(glVertexAttrib4bv, __VA_ARGS__)
#define _glVertexAttrib4d(...) callWithGLCheck(glVertexAttrib4d, __VA_ARGS__)
#define _glVertexAttrib4dv(...) callWithGLCheck(glVertexAttrib4dv, __VA_ARGS__)
#define _glVertexAttrib4f(...) callWithGLCheck(glVertexAttrib4f, __VA_ARGS__)
#define _glVertexAttrib4fv(...) callWithGLCheck(glVertexAttrib4fv, __VA_ARGS__)
#define _glVertexAttrib4iv(...) callWithGLCheck(glVertexAttrib4iv, __VA_ARGS__)
#define _glVertexAttrib4s(...) callWithGLCheck(glVertexAttrib4s, __VA_ARGS__)
#define _glVertexAttrib4sv(...) callWithGLCheck(glVertexAttrib4sv, __VA_ARGS__)
#define _glVertexAttrib4ubv(...) \
    callWithGLCheck(glVertexAttrib4ubv, __VA_ARGS__)
#define _glVertexAttrib4uiv(...) \
    callWithGLCheck(glVertexAttrib4uiv, __VA_ARGS__)
#define _glVertexAttrib4usv(...) \
    callWithGLCheck(glVertexAttrib4usv, __VA_ARGS__)
#define _glVertexAttribDivisor(...) \
    callWithGLCheck(glVertexAttribDivisor, __VA_ARGS__)
#define _glVertexAttribI1i(...) callWithGLCheck(glVertexAttribI1i, __VA_ARGS__)
#define _glVertexAttribI1iv(...) \
    callWithGLCheck(glVertexAttribI1iv, __VA_ARGS__)
#define _glVertexAttribI1ui(...) \
    callWithGLCheck(glVertexAttribI1ui, __VA_ARGS__)
#define _glVertexAttribI1uiv(...) \
    callWithGLCheck(glVertexAttribI1uiv, __VA_ARGS__)
#define _glVertexAttribI2i(...) callWithGLCheck(glVertexAttribI2i, __VA_ARGS__)
#define _glVertexAttribI2iv(...) \
    callWithGLCheck(glVertexAttribI2iv, __VA_ARGS__)
#define _glVertexAttribI2ui(...) \
    callWithGLCheck(glVertexAttribI2ui, __VA_ARGS__)
#define _glVertexAttribI2uiv(...) \
    callWithGLCheck(glVertexAttribI2uiv, __VA_ARGS__)
#define _glVertexAttribI3i(...) callWithGLCheck(glVertexAttribI3i, __VA_ARGS__)
#define _glVertexAttribI3iv(...) \
    callWithGLCheck(glVertexAttribI3iv, __VA_ARGS__)
#define _glVertexAttribI3ui(...) \
    callWithGLCheck(glVertexAttribI3ui, __VA_ARGS__)
#define _glVertexAttribI3uiv(...) \
    callWithGLCheck(glVertexAttribI3uiv, __VA_ARGS__)
#define _glVertexAttribI4bv(...) \
    callWithGLCheck(glVertexAttribI4bv, __VA_ARGS__)
#define _glVertexAttribI4i(...) callWithGLCheck(glVertexAttribI4i, __VA_ARGS__)
#define _glVertexAttribI4iv(...) \
    callWithGLCheck(glVertexAttribI4iv, __VA_ARGS__)
#define _glVertexAttribI4sv(...) \
    callWithGLCheck(glVertexAttribI4sv, __VA_ARGS__)
#define _glVertexAttribI4ubv(...) \
    callWithGLCheck(glVertexAttribI4ubv, __VA_ARGS__)
#define _glVertexAttribI4ui(...) \
    callWithGLCheck(glVertexAttribI4ui, __VA_ARGS__)
#define _glVertexAttribI4uiv(...) \
    callWithGLCheck(glVertexAttribI4uiv, __VA_ARGS__)
#define _glVertexAttribI4usv(...) \
    callWithGLCheck(glVertexAttribI4usv, __VA_ARGS__)
#define _glVertexAttribIPointer(...) \
    callWithGLCheck(glVertexAttribIPointer, __VA_ARGS__)
#define _glVertexAttribL1d(...) callWithGLCheck(glVertexAttribL1d, __VA_ARGS__)
#define _glVertexAttribL1dv(...) \
    callWithGLCheck(glVertexAttribL1dv, __VA_ARGS__)
#define _glVertexAttribL2d(...) callWithGLCheck(glVertexAttribL2d, __VA_ARGS__)
#define _glVertexAttribL2dv(...) \
    callWithGLCheck(glVertexAttribL2dv, __VA_ARGS__)
#define _glVertexAttribL3d(...) callWithGLCheck(glVertexAttribL3d, __VA_ARGS__)
#define _glVertexAttribL3dv(...) \
    callWithGLCheck(glVertexAttribL3dv, __VA_ARGS__)
#define _glVertexAttribL4d(...) callWithGLCheck(glVertexAttribL4d, __VA_ARGS__)
#define _glVertexAttribL4dv(...) \
    callWithGLCheck(glVertexAttribL4dv, __VA_ARGS__)
#define _glVertexAttribLPointer(...) \
    callWithGLCheck(glVertexAttribLPointer, __VA_ARGS__)
#define _glVertexAttribP1ui(...) \
    callWithGLCheck(glVertexAttribP1ui, __VA_ARGS__)
#define _glVertexAttribP1uiv(...) \
    callWithGLCheck(glVertexAttribP1uiv, __VA_ARGS__)
#define _glVertexAttribP2ui(...) \
    callWithGLCheck(glVertexAttribP2ui, __VA_ARGS__)
#define _glVertexAttribP2uiv(...) \
    callWithGLCheck(glVertexAttribP2uiv, __VA_ARGS__)
#define _glVertexAttribP3ui(...) \
    callWithGLCheck(glVertexAttribP3ui, __VA_ARGS__)
#define _glVertexAttribP3uiv(...) \
    callWithGLCheck(glVertexAttribP3uiv, __VA_ARGS__)
#define _glVertexAttribP4ui(...) \
    callWithGLCheck(glVertexAttribP4ui, __VA_ARGS__)
#define _glVertexAttribP4uiv(...) \
    callWithGLCheck(glVertexAttribP4uiv, __VA_ARGS__)
#define _glVertexAttribPointer(...) \
    callWithGLCheck(glVertexAttribPointer, __VA_ARGS__)
#define _glViewport(...) callWithGLCheck(glViewport, __VA_ARGS__)
#define _glViewportArrayv(...) callWithGLCheck(glViewportArrayv, __VA_ARGS__)
#define _glViewportIndexedf(...) \
    callWithGLCheck(glViewportIndexedf, __VA_ARGS__)
#define _glViewportIndexedfv(...) \
    callWithGLCheck(glViewportIndexedfv, __VA_ARGS__)
#define _glWaitSync(...) callWithGLCheck(glWaitSync, __VA_ARGS__)
#define _glBlendEquationSeparateiARB(...) \
    callWithGLCheck(glBlendEquationSeparateiARB, __VA_ARGS__)
#define _glBlendEquationiARB(...) \
    callWithGLCheck(glBlendEquationiARB, __VA_ARGS__)
#define _glBlendFuncSeparateiARB(...) \
    callWithGLCheck(glBlendFuncSeparateiARB, __VA_ARGS__)
#define _glBlendFunciARB(...) callWithGLCheck(glBlendFunciARB, __VA_ARGS__)
#define _glCompileShaderIncludeARB(...) \
    callWithGLCheck(glCompileShaderIncludeARB, __VA_ARGS__)
#define _glDeleteNamedStringARB(...) \
    callWithGLCheck(glDeleteNamedStringARB, __VA_ARGS__)
#define _glDepthBoundsEXT(...) callWithGLCheck(glDepthBoundsEXT, __VA_ARGS__)
#define _glFinishRenderAPPLE(...) \
    callWithGLCheck(glFinishRenderAPPLE, __VA_ARGS__)
#define _glFlushRenderAPPLE(...) \
    callWithGLCheck(glFlushRenderAPPLE, __VA_ARGS__)
#define _glGetInternalformativ(...) \
    callWithGLCheck(glGetInternalformativ, __VA_ARGS__)
#define _glGetNamedStringARB(...) \
    callWithGLCheck(glGetNamedStringARB, __VA_ARGS__)
#define _glGetNamedStringivARB(...) \
    callWithGLCheck(glGetNamedStringivARB, __VA_ARGS__)
#define _glGetObjectLabelEXT(...) \
    callWithGLCheck(glGetObjectLabelEXT, __VA_ARGS__)
#define _glGetObjectParameterivAPPLE(...) \
    callWithGLCheck(glGetObjectParameterivAPPLE, __VA_ARGS__)
#define _glGetTexParameterPointervAPPLE(...) \
    callWithGLCheck(glGetTexParameterPointervAPPLE, __VA_ARGS__)
#define _glInsertEventMarkerEXT(...) \
    callWithGLCheck(glInsertEventMarkerEXT, __VA_ARGS__)
#define _glIsNamedStringARB(...) \
    callWithGLCheck(glIsNamedStringARB, __VA_ARGS__)
#define _glLabelObjectEXT(...) callWithGLCheck(glLabelObjectEXT, __VA_ARGS__)
#define _glMinSampleShadingARB(...) \
    callWithGLCheck(glMinSampleShadingARB, __VA_ARGS__)
#define _glNamedStringARB(...) callWithGLCheck(glNamedStringARB, __VA_ARGS__)
#define _glObjectPurgeableAPPLE(...) \
    callWithGLCheck(glObjectPurgeableAPPLE, __VA_ARGS__)
#define _glObjectUnpurgeableAPPLE(...) \
    callWithGLCheck(glObjectUnpurgeableAPPLE, __VA_ARGS__)
#define _glPopGroupMarkerEXT(...) \
    callWithGLCheck(glPopGroupMarkerEXT, __VA_ARGS__)
#define _glPushGroupMarkerEXT(...) \
    callWithGLCheck(glPushGroupMarkerEXT, __VA_ARGS__)
#define _glSwapAPPLE(...) callWithGLCheck(glSwapAPPLE, __VA_ARGS__)
#define _glTexStorage1D(...) callWithGLCheck(glTexStorage1D, __VA_ARGS__)
#define _glTexStorage2D(...) callWithGLCheck(glTexStorage2D, __VA_ARGS__)
#define _glTexStorage3D(...) callWithGLCheck(glTexStorage3D, __VA_ARGS__)
#define _glTextureBarrierNV(...) \
    callWithGLCheck(glTextureBarrierNV, __VA_ARGS__)
#define _glTextureRangeAPPLE(...) \
    callWithGLCheck(glTextureRangeAPPLE, __VA_ARGS__)
#define _glVertexAttribDivisorARB(...) \
    callWithGLCheck(glVertexAttribDivisorARB, __VA_ARGS__)
#define _glActiveStencilFaceEXT(...) \
    callWithGLCheck(glActiveStencilFaceEXT, __VA_ARGS__)
#define _glActiveStencilFaceEXTProcPtr(...) \
    callWithGLCheck(glActiveStencilFaceEXTProcPtr, __VA_ARGS__)
#define _glActiveTextureARB(...) \
    callWithGLCheck(glActiveTextureARB, __VA_ARGS__)
#define _glActiveTextureARBProcPtr(...) \
    callWithGLCheck(glActiveTextureARBProcPtr, __VA_ARGS__)
#define _glAreProgramsResidentNV(...) \
    callWithGLCheck(glAreProgramsResidentNV, __VA_ARGS__)
#define _glAreProgramsResidentNVProcPtr(...) \
    callWithGLCheck(glAreProgramsResidentNVProcPtr, __VA_ARGS__)
#define _glAreTexturesResidentEXT(...) \
    callWithGLCheck(glAreTexturesResidentEXT, __VA_ARGS__)
#define _glAreTexturesResidentEXTProcPtr(...) \
    callWithGLCheck(glAreTexturesResidentEXTProcPtr, __VA_ARGS__)
#define _glArrayElementEXT(...) callWithGLCheck(glArrayElementEXT, __VA_ARGS__)
#define _glArrayElementEXTProcPtr(...) \
    callWithGLCheck(glArrayElementEXTProcPtr, __VA_ARGS__)
#define _glAttachObjectARB(...) callWithGLCheck(glAttachObjectARB, __VA_ARGS__)
#define _glAttachObjectARBProcPtr(...) \
    callWithGLCheck(glAttachObjectARBProcPtr, __VA_ARGS__)
#define _glBeginConditionalRenderNV(...) \
    callWithGLCheck(glBeginConditionalRenderNV, __VA_ARGS__)
#define _glBeginConditionalRenderNVProcPtr(...) \
    callWithGLCheck(glBeginConditionalRenderNVProcPtr, __VA_ARGS__)
#define _glBeginQueryARB(...) callWithGLCheck(glBeginQueryARB, __VA_ARGS__)
#define _glBeginQueryARBProcPtr(...) \
    callWithGLCheck(glBeginQueryARBProcPtr, __VA_ARGS__)
#define _glBeginTransformFeedbackEXT(...) \
    callWithGLCheck(glBeginTransformFeedbackEXT, __VA_ARGS__)
#define _glBeginTransformFeedbackEXTProcPtr(...) \
    callWithGLCheck(glBeginTransformFeedbackEXTProcPtr, __VA_ARGS__)
#define _glBindAttribLocationARB(...) \
    callWithGLCheck(glBindAttribLocationARB, __VA_ARGS__)
#define _glBindAttribLocationARBProcPtr(...) \
    callWithGLCheck(glBindAttribLocationARBProcPtr, __VA_ARGS__)
#define _glBindBufferARB(...) callWithGLCheck(glBindBufferARB, __VA_ARGS__)
#define _glBindBufferARBProcPtr(...) \
    callWithGLCheck(glBindBufferARBProcPtr, __VA_ARGS__)
#define _glBindBufferBaseEXT(...) \
    callWithGLCheck(glBindBufferBaseEXT, __VA_ARGS__)
#define _glBindBufferBaseEXTProcPtr(...) \
    callWithGLCheck(glBindBufferBaseEXTProcPtr, __VA_ARGS__)
#define _glBindBufferOffsetEXT(...) \
    callWithGLCheck(glBindBufferOffsetEXT, __VA_ARGS__)
#define _glBindBufferOffsetEXTProcPtr(...) \
    callWithGLCheck(glBindBufferOffsetEXTProcPtr, __VA_ARGS__)
#define _glBindBufferRangeEXT(...) \
    callWithGLCheck(glBindBufferRangeEXT, __VA_ARGS__)
#define _glBindBufferRangeEXTProcPtr(...) \
    callWithGLCheck(glBindBufferRangeEXTProcPtr, __VA_ARGS__)
#define _glBindFragDataLocationEXT(...) \
    callWithGLCheck(glBindFragDataLocationEXT, __VA_ARGS__)
#define _glBindFragDataLocationEXTProcPtr(...) \
    callWithGLCheck(glBindFragDataLocationEXTProcPtr, __VA_ARGS__)
#define _glBindFramebuffer(...) callWithGLCheck(glBindFramebuffer, __VA_ARGS__)
#define _glBindFramebufferEXT(...) \
    callWithGLCheck(glBindFramebufferEXT, __VA_ARGS__)
#define _glBindFramebufferEXTProcPtr(...) \
    callWithGLCheck(glBindFramebufferEXTProcPtr, __VA_ARGS__)
#define _glBindFramebufferProcPtr(...) \
    callWithGLCheck(glBindFramebufferProcPtr, __VA_ARGS__)
#define _glBindProgramARB(...) callWithGLCheck(glBindProgramARB, __VA_ARGS__)
#define _glBindProgramARBProcPtr(...) \
    callWithGLCheck(glBindProgramARBProcPtr, __VA_ARGS__)
#define _glBindProgramNV(...) callWithGLCheck(glBindProgramNV, __VA_ARGS__)
#define _glBindProgramNVProcPtr(...) \
    callWithGLCheck(glBindProgramNVProcPtr, __VA_ARGS__)
#define _glBindRenderbuffer(...) \
    callWithGLCheck(glBindRenderbuffer, __VA_ARGS__)
#define _glBindRenderbufferEXT(...) \
    callWithGLCheck(glBindRenderbufferEXT, __VA_ARGS__)
#define _glBindRenderbufferEXTProcPtr(...) \
    callWithGLCheck(glBindRenderbufferEXTProcPtr, __VA_ARGS__)
#define _glBindRenderbufferProcPtr(...) \
    callWithGLCheck(glBindRenderbufferProcPtr, __VA_ARGS__)
#define _glBindTextureEXT(...) callWithGLCheck(glBindTextureEXT, __VA_ARGS__)
#define _glBindTextureEXTProcPtr(...) \
    callWithGLCheck(glBindTextureEXTProcPtr, __VA_ARGS__)
#define _glBindVertexArrayAPPLE(...) \
    callWithGLCheck(glBindVertexArrayAPPLE, __VA_ARGS__)
#define _glBindVertexArrayAPPLEProcPtr(...) \
    callWithGLCheck(glBindVertexArrayAPPLEProcPtr, __VA_ARGS__)
#define _glBlendColorEXT(...) callWithGLCheck(glBlendColorEXT, __VA_ARGS__)
#define _glBlendColorEXTProcPtr(...) \
    callWithGLCheck(glBlendColorEXTProcPtr, __VA_ARGS__)
#define _glBlendEquationEXT(...) \
    callWithGLCheck(glBlendEquationEXT, __VA_ARGS__)
#define _glBlendEquationEXTProcPtr(...) \
    callWithGLCheck(glBlendEquationEXTProcPtr, __VA_ARGS__)
#define _glBlendEquationSeparateATI(...) \
    callWithGLCheck(glBlendEquationSeparateATI, __VA_ARGS__)
#define _glBlendEquationSeparateATIProcPtr(...) \
    callWithGLCheck(glBlendEquationSeparateATIProcPtr, __VA_ARGS__)
#define _glBlendEquationSeparateEXT(...) \
    callWithGLCheck(glBlendEquationSeparateEXT, __VA_ARGS__)
#define _glBlendEquationSeparateEXTProcPtr(...) \
    callWithGLCheck(glBlendEquationSeparateEXTProcPtr, __VA_ARGS__)
#define _glBlendFuncSeparateEXT(...) \
    callWithGLCheck(glBlendFuncSeparateEXT, __VA_ARGS__)
#define _glBlendFuncSeparateEXTProcPtr(...) \
    callWithGLCheck(glBlendFuncSeparateEXTProcPtr, __VA_ARGS__)
#define _glBlitFramebuffer(...) callWithGLCheck(glBlitFramebuffer, __VA_ARGS__)
#define _glBlitFramebufferEXT(...) \
    callWithGLCheck(glBlitFramebufferEXT, __VA_ARGS__)
#define _glBlitFramebufferEXTProcPtr(...) \
    callWithGLCheck(glBlitFramebufferEXTProcPtr, __VA_ARGS__)
#define _glBlitFramebufferProcPtr(...) \
    callWithGLCheck(glBlitFramebufferProcPtr, __VA_ARGS__)
#define _glBufferDataARB(...) callWithGLCheck(glBufferDataARB, __VA_ARGS__)
#define _glBufferDataARBProcPtr(...) \
    callWithGLCheck(glBufferDataARBProcPtr, __VA_ARGS__)
#define _glBufferParameteriAPPLE(...) \
    callWithGLCheck(glBufferParameteriAPPLE, __VA_ARGS__)
#define _glBufferParameteriAPPLEProcPtr(...) \
    callWithGLCheck(glBufferParameteriAPPLEProcPtr, __VA_ARGS__)
#define _glBufferSubDataARB(...) \
    callWithGLCheck(glBufferSubDataARB, __VA_ARGS__)
#define _glBufferSubDataARBProcPtr(...) \
    callWithGLCheck(glBufferSubDataARBProcPtr, __VA_ARGS__)
#define _glCheckFramebufferStatus(...) \
    callWithGLCheck(glCheckFramebufferStatus, __VA_ARGS__)
#define _glCheckFramebufferStatusEXT(...) \
    callWithGLCheck(glCheckFramebufferStatusEXT, __VA_ARGS__)
#define _glCheckFramebufferStatusEXTProcPtr(...) \
    callWithGLCheck(glCheckFramebufferStatusEXTProcPtr, __VA_ARGS__)
#define _glCheckFramebufferStatusProcPtr(...) \
    callWithGLCheck(glCheckFramebufferStatusProcPtr, __VA_ARGS__)
#define _glClampColorARB(...) callWithGLCheck(glClampColorARB, __VA_ARGS__)
#define _glClampColorARBProcPtr(...) \
    callWithGLCheck(glClampColorARBProcPtr, __VA_ARGS__)
#define _glClearColorIiEXT(...) callWithGLCheck(glClearColorIiEXT, __VA_ARGS__)
#define _glClearColorIiEXTProcPtr(...) \
    callWithGLCheck(glClearColorIiEXTProcPtr, __VA_ARGS__)
#define _glClearColorIuiEXT(...) \
    callWithGLCheck(glClearColorIuiEXT, __VA_ARGS__)
#define _glClearColorIuiEXTProcPtr(...) \
    callWithGLCheck(glClearColorIuiEXTProcPtr, __VA_ARGS__)
#define _glClientActiveTextureARB(...) \
    callWithGLCheck(glClientActiveTextureARB, __VA_ARGS__)
#define _glClientActiveTextureARBProcPtr(...) \
    callWithGLCheck(glClientActiveTextureARBProcPtr, __VA_ARGS__)
#define _glClientWaitSync(...) callWithGLCheck(glClientWaitSync, __VA_ARGS__)
#define _glClientWaitSyncProcPtr(...) \
    callWithGLCheck(glClientWaitSyncProcPtr, __VA_ARGS__)
#define _glColorMaskIndexedEXT(...) \
    callWithGLCheck(glColorMaskIndexedEXT, __VA_ARGS__)
#define _glColorMaskIndexedEXTProcPtr(...) \
    callWithGLCheck(glColorMaskIndexedEXTProcPtr, __VA_ARGS__)
#define _glColorPointerEXT(...) callWithGLCheck(glColorPointerEXT, __VA_ARGS__)
#define _glColorPointerEXTProcPtr(...) \
    callWithGLCheck(glColorPointerEXTProcPtr, __VA_ARGS__)
#define _glColorSubTableEXT(...) \
    callWithGLCheck(glColorSubTableEXT, __VA_ARGS__)
#define _glColorSubTableEXTProcPtr(...) \
    callWithGLCheck(glColorSubTableEXTProcPtr, __VA_ARGS__)
#define _glColorTableEXT(...) callWithGLCheck(glColorTableEXT, __VA_ARGS__)
#define _glColorTableEXTProcPtr(...) \
    callWithGLCheck(glColorTableEXTProcPtr, __VA_ARGS__)
#define _glColorTableParameterfvSGI(...) \
    callWithGLCheck(glColorTableParameterfvSGI, __VA_ARGS__)
#define _glColorTableParameterfvSGIProcPtr(...) \
    callWithGLCheck(glColorTableParameterfvSGIProcPtr, __VA_ARGS__)
#define _glColorTableParameterivSGI(...) \
    callWithGLCheck(glColorTableParameterivSGI, __VA_ARGS__)
#define _glColorTableParameterivSGIProcPtr(...) \
    callWithGLCheck(glColorTableParameterivSGIProcPtr, __VA_ARGS__)
#define _glColorTableSGI(...) callWithGLCheck(glColorTableSGI, __VA_ARGS__)
#define _glColorTableSGIProcPtr(...) \
    callWithGLCheck(glColorTableSGIProcPtr, __VA_ARGS__)
#define _glCombinerInputNV(...) callWithGLCheck(glCombinerInputNV, __VA_ARGS__)
#define _glCombinerInputNVProcPtr(...) \
    callWithGLCheck(glCombinerInputNVProcPtr, __VA_ARGS__)
#define _glCombinerOutputNV(...) \
    callWithGLCheck(glCombinerOutputNV, __VA_ARGS__)
#define _glCombinerOutputNVProcPtr(...) \
    callWithGLCheck(glCombinerOutputNVProcPtr, __VA_ARGS__)
#define _glCombinerParameterfNV(...) \
    callWithGLCheck(glCombinerParameterfNV, __VA_ARGS__)
#define _glCombinerParameterfNVProcPtr(...) \
    callWithGLCheck(glCombinerParameterfNVProcPtr, __VA_ARGS__)
#define _glCombinerParameterfvNV(...) \
    callWithGLCheck(glCombinerParameterfvNV, __VA_ARGS__)
#define _glCombinerParameterfvNVProcPtr(...) \
    callWithGLCheck(glCombinerParameterfvNVProcPtr, __VA_ARGS__)
#define _glCombinerParameteriNV(...) \
    callWithGLCheck(glCombinerParameteriNV, __VA_ARGS__)
#define _glCombinerParameteriNVProcPtr(...) \
    callWithGLCheck(glCombinerParameteriNVProcPtr, __VA_ARGS__)
#define _glCombinerParameterivNV(...) \
    callWithGLCheck(glCombinerParameterivNV, __VA_ARGS__)
#define _glCombinerParameterivNVProcPtr(...) \
    callWithGLCheck(glCombinerParameterivNVProcPtr, __VA_ARGS__)
#define _glCombinerStageParameterfvNV(...) \
    callWithGLCheck(glCombinerStageParameterfvNV, __VA_ARGS__)
#define _glCombinerStageParameterfvNVProcPtr(...) \
    callWithGLCheck(glCombinerStageParameterfvNVProcPtr, __VA_ARGS__)
#define _glCompileShaderARB(...) \
    callWithGLCheck(glCompileShaderARB, __VA_ARGS__)
#define _glCompileShaderARBProcPtr(...) \
    callWithGLCheck(glCompileShaderARBProcPtr, __VA_ARGS__)
#define _glCompressedTexImage1DARB(...) \
    callWithGLCheck(glCompressedTexImage1DARB, __VA_ARGS__)
#define _glCompressedTexImage1DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexImage1DARBProcPtr, __VA_ARGS__)
#define _glCompressedTexImage2DARB(...) \
    callWithGLCheck(glCompressedTexImage2DARB, __VA_ARGS__)
#define _glCompressedTexImage2DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexImage2DARBProcPtr, __VA_ARGS__)
#define _glCompressedTexImage3DARB(...) \
    callWithGLCheck(glCompressedTexImage3DARB, __VA_ARGS__)
#define _glCompressedTexImage3DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexImage3DARBProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage1DARB(...) \
    callWithGLCheck(glCompressedTexSubImage1DARB, __VA_ARGS__)
#define _glCompressedTexSubImage1DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage1DARBProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage2DARB(...) \
    callWithGLCheck(glCompressedTexSubImage2DARB, __VA_ARGS__)
#define _glCompressedTexSubImage2DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage2DARBProcPtr, __VA_ARGS__)
#define _glCompressedTexSubImage3DARB(...) \
    callWithGLCheck(glCompressedTexSubImage3DARB, __VA_ARGS__)
#define _glCompressedTexSubImage3DARBProcPtr(...) \
    callWithGLCheck(glCompressedTexSubImage3DARBProcPtr, __VA_ARGS__)
#define _glConvolutionFilter1DEXT(...) \
    callWithGLCheck(glConvolutionFilter1DEXT, __VA_ARGS__)
#define _glConvolutionFilter1DEXTProcPtr(...) \
    callWithGLCheck(glConvolutionFilter1DEXTProcPtr, __VA_ARGS__)
#define _glConvolutionFilter2DEXT(...) \
    callWithGLCheck(glConvolutionFilter2DEXT, __VA_ARGS__)
#define _glConvolutionFilter2DEXTProcPtr(...) \
    callWithGLCheck(glConvolutionFilter2DEXTProcPtr, __VA_ARGS__)
#define _glConvolutionParameterfEXT(...) \
    callWithGLCheck(glConvolutionParameterfEXT, __VA_ARGS__)
#define _glConvolutionParameterfEXTProcPtr(...) \
    callWithGLCheck(glConvolutionParameterfEXTProcPtr, __VA_ARGS__)
#define _glConvolutionParameterfvEXT(...) \
    callWithGLCheck(glConvolutionParameterfvEXT, __VA_ARGS__)
#define _glConvolutionParameterfvEXTProcPtr(...) \
    callWithGLCheck(glConvolutionParameterfvEXTProcPtr, __VA_ARGS__)
#define _glConvolutionParameteriEXT(...) \
    callWithGLCheck(glConvolutionParameteriEXT, __VA_ARGS__)
#define _glConvolutionParameteriEXTProcPtr(...) \
    callWithGLCheck(glConvolutionParameteriEXTProcPtr, __VA_ARGS__)
#define _glConvolutionParameterivEXT(...) \
    callWithGLCheck(glConvolutionParameterivEXT, __VA_ARGS__)
#define _glConvolutionParameterivEXTProcPtr(...) \
    callWithGLCheck(glConvolutionParameterivEXTProcPtr, __VA_ARGS__)
#define _glCopyColorSubTableEXT(...) \
    callWithGLCheck(glCopyColorSubTableEXT, __VA_ARGS__)
#define _glCopyColorSubTableEXTProcPtr(...) \
    callWithGLCheck(glCopyColorSubTableEXTProcPtr, __VA_ARGS__)
#define _glCopyColorTableSGI(...) \
    callWithGLCheck(glCopyColorTableSGI, __VA_ARGS__)
#define _glCopyColorTableSGIProcPtr(...) \
    callWithGLCheck(glCopyColorTableSGIProcPtr, __VA_ARGS__)
#define _glCopyConvolutionFilter1DEXT(...) \
    callWithGLCheck(glCopyConvolutionFilter1DEXT, __VA_ARGS__)
#define _glCopyConvolutionFilter1DEXTProcPtr(...) \
    callWithGLCheck(glCopyConvolutionFilter1DEXTProcPtr, __VA_ARGS__)
#define _glCopyConvolutionFilter2DEXT(...) \
    callWithGLCheck(glCopyConvolutionFilter2DEXT, __VA_ARGS__)
#define _glCopyConvolutionFilter2DEXTProcPtr(...) \
    callWithGLCheck(glCopyConvolutionFilter2DEXTProcPtr, __VA_ARGS__)
#define _glCopyTexImage1DEXT(...) \
    callWithGLCheck(glCopyTexImage1DEXT, __VA_ARGS__)
#define _glCopyTexImage1DEXTProcPtr(...) \
    callWithGLCheck(glCopyTexImage1DEXTProcPtr, __VA_ARGS__)
#define _glCopyTexImage2DEXT(...) \
    callWithGLCheck(glCopyTexImage2DEXT, __VA_ARGS__)
#define _glCopyTexImage2DEXTProcPtr(...) \
    callWithGLCheck(glCopyTexImage2DEXTProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage1DEXT(...) \
    callWithGLCheck(glCopyTexSubImage1DEXT, __VA_ARGS__)
#define _glCopyTexSubImage1DEXTProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage1DEXTProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage2DEXT(...) \
    callWithGLCheck(glCopyTexSubImage2DEXT, __VA_ARGS__)
#define _glCopyTexSubImage2DEXTProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage2DEXTProcPtr, __VA_ARGS__)
#define _glCopyTexSubImage3DEXT(...) \
    callWithGLCheck(glCopyTexSubImage3DEXT, __VA_ARGS__)
#define _glCopyTexSubImage3DEXTProcPtr(...) \
    callWithGLCheck(glCopyTexSubImage3DEXTProcPtr, __VA_ARGS__)
#define _glCreateProgramObjectARB(...) \
    callWithGLCheck(glCreateProgramObjectARB, __VA_ARGS__)
#define _glCreateProgramObjectARBProcPtr(...) \
    callWithGLCheck(glCreateProgramObjectARBProcPtr, __VA_ARGS__)
#define _glCreateShaderObjectARB(...) \
    callWithGLCheck(glCreateShaderObjectARB, __VA_ARGS__)
#define _glCreateShaderObjectARBProcPtr(...) \
    callWithGLCheck(glCreateShaderObjectARBProcPtr, __VA_ARGS__)
#define _glDeleteBuffersARB(...) \
    callWithGLCheck(glDeleteBuffersARB, __VA_ARGS__)
#define _glDeleteBuffersARBProcPtr(...) \
    callWithGLCheck(glDeleteBuffersARBProcPtr, __VA_ARGS__)
#define _glDeleteFencesAPPLE(...) \
    callWithGLCheck(glDeleteFencesAPPLE, __VA_ARGS__)
#define _glDeleteFencesAPPLEProcPtr(...) \
    callWithGLCheck(glDeleteFencesAPPLEProcPtr, __VA_ARGS__)
#define _glDeleteFramebuffers(...) \
    callWithGLCheck(glDeleteFramebuffers, __VA_ARGS__)
#define _glDeleteFramebuffersEXT(...) \
    callWithGLCheck(glDeleteFramebuffersEXT, __VA_ARGS__)
#define _glDeleteFramebuffersEXTProcPtr(...) \
    callWithGLCheck(glDeleteFramebuffersEXTProcPtr, __VA_ARGS__)
#define _glDeleteFramebuffersProcPtr(...) \
    callWithGLCheck(glDeleteFramebuffersProcPtr, __VA_ARGS__)
#define _glDeleteObjectARB(...) callWithGLCheck(glDeleteObjectARB, __VA_ARGS__)
#define _glDeleteObjectARBProcPtr(...) \
    callWithGLCheck(glDeleteObjectARBProcPtr, __VA_ARGS__)
#define _glDeleteProgramsARB(...) \
    callWithGLCheck(glDeleteProgramsARB, __VA_ARGS__)
#define _glDeleteProgramsARBProcPtr(...) \
    callWithGLCheck(glDeleteProgramsARBProcPtr, __VA_ARGS__)
#define _glDeleteProgramsNV(...) \
    callWithGLCheck(glDeleteProgramsNV, __VA_ARGS__)
#define _glDeleteProgramsNVProcPtr(...) \
    callWithGLCheck(glDeleteProgramsNVProcPtr, __VA_ARGS__)
#define _glDeleteQueriesARB(...) \
    callWithGLCheck(glDeleteQueriesARB, __VA_ARGS__)
#define _glDeleteQueriesARBProcPtr(...) \
    callWithGLCheck(glDeleteQueriesARBProcPtr, __VA_ARGS__)
#define _glDeleteRenderbuffers(...) \
    callWithGLCheck(glDeleteRenderbuffers, __VA_ARGS__)
#define _glDeleteRenderbuffersEXT(...) \
    callWithGLCheck(glDeleteRenderbuffersEXT, __VA_ARGS__)
#define _glDeleteRenderbuffersEXTProcPtr(...) \
    callWithGLCheck(glDeleteRenderbuffersEXTProcPtr, __VA_ARGS__)
#define _glDeleteRenderbuffersProcPtr(...) \
    callWithGLCheck(glDeleteRenderbuffersProcPtr, __VA_ARGS__)
#define _glDeleteSync(...) callWithGLCheck(glDeleteSync, __VA_ARGS__)
#define _glDeleteSyncProcPtr(...) \
    callWithGLCheck(glDeleteSyncProcPtr, __VA_ARGS__)
#define _glDeleteTexturesEXT(...) \
    callWithGLCheck(glDeleteTexturesEXT, __VA_ARGS__)
#define _glDeleteTexturesEXTProcPtr(...) \
    callWithGLCheck(glDeleteTexturesEXTProcPtr, __VA_ARGS__)
#define _glDeleteVertexArraysAPPLE(...) \
    callWithGLCheck(glDeleteVertexArraysAPPLE, __VA_ARGS__)
#define _glDeleteVertexArraysAPPLEProcPtr(...) \
    callWithGLCheck(glDeleteVertexArraysAPPLEProcPtr, __VA_ARGS__)
#define _glDepthBoundsEXT(...) callWithGLCheck(glDepthBoundsEXT, __VA_ARGS__)
#define _glDepthBoundsEXTProcPtr(...) \
    callWithGLCheck(glDepthBoundsEXTProcPtr, __VA_ARGS__)
#define _glDetachObjectARB(...) callWithGLCheck(glDetachObjectARB, __VA_ARGS__)
#define _glDetachObjectARBProcPtr(...) \
    callWithGLCheck(glDetachObjectARBProcPtr, __VA_ARGS__)
#define _glDisableIndexedEXT(...) \
    callWithGLCheck(glDisableIndexedEXT, __VA_ARGS__)
#define _glDisableIndexedEXTProcPtr(...) \
    callWithGLCheck(glDisableIndexedEXTProcPtr, __VA_ARGS__)
#define _glDisableVertexAttribAPPLE(...) \
    callWithGLCheck(glDisableVertexAttribAPPLE, __VA_ARGS__)
#define _glDisableVertexAttribAPPLEProcPtr(...) \
    callWithGLCheck(glDisableVertexAttribAPPLEProcPtr, __VA_ARGS__)
#define _glDisableVertexAttribArrayARB(...) \
    callWithGLCheck(glDisableVertexAttribArrayARB, __VA_ARGS__)
#define _glDisableVertexAttribArrayARBProcPtr(...) \
    callWithGLCheck(glDisableVertexAttribArrayARBProcPtr, __VA_ARGS__)
#define _glDrawArraysEXT(...) callWithGLCheck(glDrawArraysEXT, __VA_ARGS__)
#define _glDrawArraysEXTProcPtr(...) \
    callWithGLCheck(glDrawArraysEXTProcPtr, __VA_ARGS__)
#define _glDrawArraysInstancedARB(...) \
    callWithGLCheck(glDrawArraysInstancedARB, __VA_ARGS__)
#define _glDrawArraysInstancedARBProcPtr(...) \
    callWithGLCheck(glDrawArraysInstancedARBProcPtr, __VA_ARGS__)
#define _glDrawBuffersARB(...) callWithGLCheck(glDrawBuffersARB, __VA_ARGS__)
#define _glDrawBuffersARBProcPtr(...) \
    callWithGLCheck(glDrawBuffersARBProcPtr, __VA_ARGS__)
#define _glDrawElementArrayAPPLE(...) \
    callWithGLCheck(glDrawElementArrayAPPLE, __VA_ARGS__)
#define _glDrawElementArrayAPPLEProcPtr(...) \
    callWithGLCheck(glDrawElementArrayAPPLEProcPtr, __VA_ARGS__)
#define _glDrawElementsBaseVertex(...) \
    callWithGLCheck(glDrawElementsBaseVertex, __VA_ARGS__)
#define _glDrawElementsBaseVertexProcPtr(...) \
    callWithGLCheck(glDrawElementsBaseVertexProcPtr, __VA_ARGS__)
#define _glDrawElementsInstancedARB(...) \
    callWithGLCheck(glDrawElementsInstancedARB, __VA_ARGS__)
#define _glDrawElementsInstancedARBProcPtr(...) \
    callWithGLCheck(glDrawElementsInstancedARBProcPtr, __VA_ARGS__)
#define _glDrawElementsInstancedBaseVertex(...) \
    callWithGLCheck(glDrawElementsInstancedBaseVertex, __VA_ARGS__)
#define _glDrawElementsInstancedBaseVertexProcPtr(...) \
    callWithGLCheck(glDrawElementsInstancedBaseVertexProcPtr, __VA_ARGS__)
#define _glDrawRangeElementArrayAPPLE(...) \
    callWithGLCheck(glDrawRangeElementArrayAPPLE, __VA_ARGS__)
#define _glDrawRangeElementArrayAPPLEProcPtr(...) \
    callWithGLCheck(glDrawRangeElementArrayAPPLEProcPtr, __VA_ARGS__)
#define _glDrawRangeElementsBaseVertex(...) \
    callWithGLCheck(glDrawRangeElementsBaseVertex, __VA_ARGS__)
#define _glDrawRangeElementsBaseVertexProcPtr(...) \
    callWithGLCheck(glDrawRangeElementsBaseVertexProcPtr, __VA_ARGS__)
#define _glDrawRangeElementsEXT(...) \
    callWithGLCheck(glDrawRangeElementsEXT, __VA_ARGS__)
#define _glDrawRangeElementsEXTProcPtr(...) \
    callWithGLCheck(glDrawRangeElementsEXTProcPtr, __VA_ARGS__)
#define _glEdgeFlagPointerEXT(...) \
    callWithGLCheck(glEdgeFlagPointerEXT, __VA_ARGS__)
#define _glEdgeFlagPointerEXTProcPtr(...) \
    callWithGLCheck(glEdgeFlagPointerEXTProcPtr, __VA_ARGS__)
#define _glElementPointerAPPLE(...) \
    callWithGLCheck(glElementPointerAPPLE, __VA_ARGS__)
#define _glElementPointerAPPLEProcPtr(...) \
    callWithGLCheck(glElementPointerAPPLEProcPtr, __VA_ARGS__)
#define _glEnableIndexedEXT(...) \
    callWithGLCheck(glEnableIndexedEXT, __VA_ARGS__)
#define _glEnableIndexedEXTProcPtr(...) \
    callWithGLCheck(glEnableIndexedEXTProcPtr, __VA_ARGS__)
#define _glEnableVertexAttribAPPLE(...) \
    callWithGLCheck(glEnableVertexAttribAPPLE, __VA_ARGS__)
#define _glEnableVertexAttribAPPLEProcPtr(...) \
    callWithGLCheck(glEnableVertexAttribAPPLEProcPtr, __VA_ARGS__)
#define _glEnableVertexAttribArrayARB(...) \
    callWithGLCheck(glEnableVertexAttribArrayARB, __VA_ARGS__)
#define _glEnableVertexAttribArrayARBProcPtr(...) \
    callWithGLCheck(glEnableVertexAttribArrayARBProcPtr, __VA_ARGS__)
#define _glEndConditionalRenderNV(...) \
    callWithGLCheck(glEndConditionalRenderNV, __VA_ARGS__)
#define _glEndConditionalRenderNVProcPtr(...) \
    callWithGLCheck(glEndConditionalRenderNVProcPtr, __VA_ARGS__)
#define _glEndQueryARB(...) callWithGLCheck(glEndQueryARB, __VA_ARGS__)
#define _glEndQueryARBProcPtr(...) \
    callWithGLCheck(glEndQueryARBProcPtr, __VA_ARGS__)
#define _glEndTransformFeedbackEXT(...) \
    callWithGLCheck(glEndTransformFeedbackEXT, __VA_ARGS__)
#define _glEndTransformFeedbackEXTProcPtr(...) \
    callWithGLCheck(glEndTransformFeedbackEXTProcPtr, __VA_ARGS__)
#define _glExecuteProgramNV(...) \
    callWithGLCheck(glExecuteProgramNV, __VA_ARGS__)
#define _glExecuteProgramNVProcPtr(...) \
    callWithGLCheck(glExecuteProgramNVProcPtr, __VA_ARGS__)
#define _glFenceSync(...) callWithGLCheck(glFenceSync, __VA_ARGS__)
#define _glFenceSyncProcPtr(...) \
    callWithGLCheck(glFenceSyncProcPtr, __VA_ARGS__)
#define _glFinalCombinerInputNV(...) \
    callWithGLCheck(glFinalCombinerInputNV, __VA_ARGS__)
#define _glFinalCombinerInputNVProcPtr(...) \
    callWithGLCheck(glFinalCombinerInputNVProcPtr, __VA_ARGS__)
#define _glFinishFenceAPPLE(...) \
    callWithGLCheck(glFinishFenceAPPLE, __VA_ARGS__)
#define _glFinishFenceAPPLEProcPtr(...) \
    callWithGLCheck(glFinishFenceAPPLEProcPtr, __VA_ARGS__)
#define _glFinishObjectAPPLE(...) \
    callWithGLCheck(glFinishObjectAPPLE, __VA_ARGS__)
#define _glFinishObjectAPPLEProcPtr(...) \
    callWithGLCheck(glFinishObjectAPPLEProcPtr, __VA_ARGS__)
#define _glFinishRenderAPPLE(...) \
    callWithGLCheck(glFinishRenderAPPLE, __VA_ARGS__)
#define _glFinishRenderAPPLEProcPtr(...) \
    callWithGLCheck(glFinishRenderAPPLEProcPtr, __VA_ARGS__)
#define _glFlushMappedBufferRangeAPPLE(...) \
    callWithGLCheck(glFlushMappedBufferRangeAPPLE, __VA_ARGS__)
#define _glFlushMappedBufferRangeAPPLEProcPtr(...) \
    callWithGLCheck(glFlushMappedBufferRangeAPPLEProcPtr, __VA_ARGS__)
#define _glFlushRenderAPPLE(...) \
    callWithGLCheck(glFlushRenderAPPLE, __VA_ARGS__)
#define _glFlushRenderAPPLEProcPtr(...) \
    callWithGLCheck(glFlushRenderAPPLEProcPtr, __VA_ARGS__)
#define _glFlushVertexArrayRangeAPPLE(...) \
    callWithGLCheck(glFlushVertexArrayRangeAPPLE, __VA_ARGS__)
#define _glFlushVertexArrayRangeAPPLEProcPtr(...) \
    callWithGLCheck(glFlushVertexArrayRangeAPPLEProcPtr, __VA_ARGS__)
#define _glFlushVertexArrayRangeNV(...) \
    callWithGLCheck(glFlushVertexArrayRangeNV, __VA_ARGS__)
#define _glFlushVertexArrayRangeNVProcPtr(...) \
    callWithGLCheck(glFlushVertexArrayRangeNVProcPtr, __VA_ARGS__)
#define _glFogCoordPointerEXT(...) \
    callWithGLCheck(glFogCoordPointerEXT, __VA_ARGS__)
#define _glFogCoordPointerEXTProcPtr(...) \
    callWithGLCheck(glFogCoordPointerEXTProcPtr, __VA_ARGS__)
#define _glFogCoorddEXT(...) callWithGLCheck(glFogCoorddEXT, __VA_ARGS__)
#define _glFogCoorddEXTProcPtr(...) \
    callWithGLCheck(glFogCoorddEXTProcPtr, __VA_ARGS__)
#define _glFogCoorddvEXT(...) callWithGLCheck(glFogCoorddvEXT, __VA_ARGS__)
#define _glFogCoorddvEXTProcPtr(...) \
    callWithGLCheck(glFogCoorddvEXTProcPtr, __VA_ARGS__)
#define _glFogCoordfEXT(...) callWithGLCheck(glFogCoordfEXT, __VA_ARGS__)
#define _glFogCoordfEXTProcPtr(...) \
    callWithGLCheck(glFogCoordfEXTProcPtr, __VA_ARGS__)
#define _glFogCoordfvEXT(...) callWithGLCheck(glFogCoordfvEXT, __VA_ARGS__)
#define _glFogCoordfvEXTProcPtr(...) \
    callWithGLCheck(glFogCoordfvEXTProcPtr, __VA_ARGS__)
#define _glFramebufferRenderbuffer(...) \
    callWithGLCheck(glFramebufferRenderbuffer, __VA_ARGS__)
#define _glFramebufferRenderbufferEXT(...) \
    callWithGLCheck(glFramebufferRenderbufferEXT, __VA_ARGS__)
#define _glFramebufferRenderbufferEXTProcPtr(...) \
    callWithGLCheck(glFramebufferRenderbufferEXTProcPtr, __VA_ARGS__)
#define _glFramebufferRenderbufferProcPtr(...) \
    callWithGLCheck(glFramebufferRenderbufferProcPtr, __VA_ARGS__)
#define _glFramebufferTexture1D(...) \
    callWithGLCheck(glFramebufferTexture1D, __VA_ARGS__)
#define _glFramebufferTexture1DEXT(...) \
    callWithGLCheck(glFramebufferTexture1DEXT, __VA_ARGS__)
#define _glFramebufferTexture1DEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTexture1DEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTexture1DProcPtr(...) \
    callWithGLCheck(glFramebufferTexture1DProcPtr, __VA_ARGS__)
#define _glFramebufferTexture2D(...) \
    callWithGLCheck(glFramebufferTexture2D, __VA_ARGS__)
#define _glFramebufferTexture2DEXT(...) \
    callWithGLCheck(glFramebufferTexture2DEXT, __VA_ARGS__)
#define _glFramebufferTexture2DEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTexture2DEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTexture2DProcPtr(...) \
    callWithGLCheck(glFramebufferTexture2DProcPtr, __VA_ARGS__)
#define _glFramebufferTexture3D(...) \
    callWithGLCheck(glFramebufferTexture3D, __VA_ARGS__)
#define _glFramebufferTexture3DEXT(...) \
    callWithGLCheck(glFramebufferTexture3DEXT, __VA_ARGS__)
#define _glFramebufferTexture3DEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTexture3DEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTexture3DProcPtr(...) \
    callWithGLCheck(glFramebufferTexture3DProcPtr, __VA_ARGS__)
#define _glFramebufferTextureEXT(...) \
    callWithGLCheck(glFramebufferTextureEXT, __VA_ARGS__)
#define _glFramebufferTextureEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTextureEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTextureFaceEXT(...) \
    callWithGLCheck(glFramebufferTextureFaceEXT, __VA_ARGS__)
#define _glFramebufferTextureFaceEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTextureFaceEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTextureLayer(...) \
    callWithGLCheck(glFramebufferTextureLayer, __VA_ARGS__)
#define _glFramebufferTextureLayerEXT(...) \
    callWithGLCheck(glFramebufferTextureLayerEXT, __VA_ARGS__)
#define _glFramebufferTextureLayerEXTProcPtr(...) \
    callWithGLCheck(glFramebufferTextureLayerEXTProcPtr, __VA_ARGS__)
#define _glFramebufferTextureLayerProcPtr(...) \
    callWithGLCheck(glFramebufferTextureLayerProcPtr, __VA_ARGS__)
#define _glGenBuffersARB(...) callWithGLCheck(glGenBuffersARB, __VA_ARGS__)
#define _glGenBuffersARBProcPtr(...) \
    callWithGLCheck(glGenBuffersARBProcPtr, __VA_ARGS__)
#define _glGenFencesAPPLE(...) callWithGLCheck(glGenFencesAPPLE, __VA_ARGS__)
#define _glGenFencesAPPLEProcPtr(...) \
    callWithGLCheck(glGenFencesAPPLEProcPtr, __VA_ARGS__)
#define _glGenFramebuffers(...) callWithGLCheck(glGenFramebuffers, __VA_ARGS__)
#define _glGenFramebuffersEXT(...) \
    callWithGLCheck(glGenFramebuffersEXT, __VA_ARGS__)
#define _glGenFramebuffersEXTProcPtr(...) \
    callWithGLCheck(glGenFramebuffersEXTProcPtr, __VA_ARGS__)
#define _glGenFramebuffersProcPtr(...) \
    callWithGLCheck(glGenFramebuffersProcPtr, __VA_ARGS__)
#define _glGenProgramsARB(...) callWithGLCheck(glGenProgramsARB, __VA_ARGS__)
#define _glGenProgramsARBProcPtr(...) \
    callWithGLCheck(glGenProgramsARBProcPtr, __VA_ARGS__)
#define _glGenProgramsNV(...) callWithGLCheck(glGenProgramsNV, __VA_ARGS__)
#define _glGenProgramsNVProcPtr(...) \
    callWithGLCheck(glGenProgramsNVProcPtr, __VA_ARGS__)
#define _glGenQueriesARB(...) callWithGLCheck(glGenQueriesARB, __VA_ARGS__)
#define _glGenQueriesARBProcPtr(...) \
    callWithGLCheck(glGenQueriesARBProcPtr, __VA_ARGS__)
#define _glGenRenderbuffers(...) \
    callWithGLCheck(glGenRenderbuffers, __VA_ARGS__)
#define _glGenRenderbuffersEXT(...) \
    callWithGLCheck(glGenRenderbuffersEXT, __VA_ARGS__)
#define _glGenRenderbuffersEXTProcPtr(...) \
    callWithGLCheck(glGenRenderbuffersEXTProcPtr, __VA_ARGS__)
#define _glGenRenderbuffersProcPtr(...) \
    callWithGLCheck(glGenRenderbuffersProcPtr, __VA_ARGS__)
#define _glGenTexturesEXT(...) callWithGLCheck(glGenTexturesEXT, __VA_ARGS__)
#define _glGenTexturesEXTProcPtr(...) \
    callWithGLCheck(glGenTexturesEXTProcPtr, __VA_ARGS__)
#define _glGenVertexArraysAPPLE(...) \
    callWithGLCheck(glGenVertexArraysAPPLE, __VA_ARGS__)
#define _glGenVertexArraysAPPLEProcPtr(...) \
    callWithGLCheck(glGenVertexArraysAPPLEProcPtr, __VA_ARGS__)
#define _glGenerateMipmap(...) callWithGLCheck(glGenerateMipmap, __VA_ARGS__)
#define _glGenerateMipmapEXT(...) \
    callWithGLCheck(glGenerateMipmapEXT, __VA_ARGS__)
#define _glGenerateMipmapEXTProcPtr(...) \
    callWithGLCheck(glGenerateMipmapEXTProcPtr, __VA_ARGS__)
#define _glGenerateMipmapProcPtr(...) \
    callWithGLCheck(glGenerateMipmapProcPtr, __VA_ARGS__)
#define _glGetActiveAttribARB(...) \
    callWithGLCheck(glGetActiveAttribARB, __VA_ARGS__)
#define _glGetActiveAttribARBProcPtr(...) \
    callWithGLCheck(glGetActiveAttribARBProcPtr, __VA_ARGS__)
#define _glGetActiveUniformARB(...) \
    callWithGLCheck(glGetActiveUniformARB, __VA_ARGS__)
#define _glGetActiveUniformARBProcPtr(...) \
    callWithGLCheck(glGetActiveUniformARBProcPtr, __VA_ARGS__)
#define _glGetAttachedObjectsARB(...) \
    callWithGLCheck(glGetAttachedObjectsARB, __VA_ARGS__)
#define _glGetAttachedObjectsARBProcPtr(...) \
    callWithGLCheck(glGetAttachedObjectsARBProcPtr, __VA_ARGS__)
#define _glGetAttribLocationARB(...) \
    callWithGLCheck(glGetAttribLocationARB, __VA_ARGS__)
#define _glGetAttribLocationARBProcPtr(...) \
    callWithGLCheck(glGetAttribLocationARBProcPtr, __VA_ARGS__)
#define _glGetBooleanIndexedvEXT(...) \
    callWithGLCheck(glGetBooleanIndexedvEXT, __VA_ARGS__)
#define _glGetBooleanIndexedvEXTProcPtr(...) \
    callWithGLCheck(glGetBooleanIndexedvEXTProcPtr, __VA_ARGS__)
#define _glGetBufferParameterivARB(...) \
    callWithGLCheck(glGetBufferParameterivARB, __VA_ARGS__)
#define _glGetBufferParameterivARBProcPtr(...) \
    callWithGLCheck(glGetBufferParameterivARBProcPtr, __VA_ARGS__)
#define _glGetBufferPointervARB(...) \
    callWithGLCheck(glGetBufferPointervARB, __VA_ARGS__)
#define _glGetBufferPointervARBProcPtr(...) \
    callWithGLCheck(glGetBufferPointervARBProcPtr, __VA_ARGS__)
#define _glGetBufferSubDataARB(...) \
    callWithGLCheck(glGetBufferSubDataARB, __VA_ARGS__)
#define _glGetBufferSubDataARBProcPtr(...) \
    callWithGLCheck(glGetBufferSubDataARBProcPtr, __VA_ARGS__)
#define _glGetColorTableEXT(...) \
    callWithGLCheck(glGetColorTableEXT, __VA_ARGS__)
#define _glGetColorTableEXTProcPtr(...) \
    callWithGLCheck(glGetColorTableEXTProcPtr, __VA_ARGS__)
#define _glGetColorTableParameterfvEXT(...) \
    callWithGLCheck(glGetColorTableParameterfvEXT, __VA_ARGS__)
#define _glGetColorTableParameterfvEXTProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterfvEXTProcPtr, __VA_ARGS__)
#define _glGetColorTableParameterfvSGI(...) \
    callWithGLCheck(glGetColorTableParameterfvSGI, __VA_ARGS__)
#define _glGetColorTableParameterfvSGIProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterfvSGIProcPtr, __VA_ARGS__)
#define _glGetColorTableParameterivEXT(...) \
    callWithGLCheck(glGetColorTableParameterivEXT, __VA_ARGS__)
#define _glGetColorTableParameterivEXTProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterivEXTProcPtr, __VA_ARGS__)
#define _glGetColorTableParameterivSGI(...) \
    callWithGLCheck(glGetColorTableParameterivSGI, __VA_ARGS__)
#define _glGetColorTableParameterivSGIProcPtr(...) \
    callWithGLCheck(glGetColorTableParameterivSGIProcPtr, __VA_ARGS__)
#define _glGetColorTableSGI(...) \
    callWithGLCheck(glGetColorTableSGI, __VA_ARGS__)
#define _glGetColorTableSGIProcPtr(...) \
    callWithGLCheck(glGetColorTableSGIProcPtr, __VA_ARGS__)
#define _glGetCombinerInputParameterfvNV(...) \
    callWithGLCheck(glGetCombinerInputParameterfvNV, __VA_ARGS__)
#define _glGetCombinerInputParameterfvNVProcPtr(...) \
    callWithGLCheck(glGetCombinerInputParameterfvNVProcPtr, __VA_ARGS__)
#define _glGetCombinerInputParameterivNV(...) \
    callWithGLCheck(glGetCombinerInputParameterivNV, __VA_ARGS__)
#define _glGetCombinerInputParameterivNVProcPtr(...) \
    callWithGLCheck(glGetCombinerInputParameterivNVProcPtr, __VA_ARGS__)
#define _glGetCombinerOutputParameterfvNV(...) \
    callWithGLCheck(glGetCombinerOutputParameterfvNV, __VA_ARGS__)
#define _glGetCombinerOutputParameterfvNVProcPtr(...) \
    callWithGLCheck(glGetCombinerOutputParameterfvNVProcPtr, __VA_ARGS__)
#define _glGetCombinerOutputParameterivNV(...) \
    callWithGLCheck(glGetCombinerOutputParameterivNV, __VA_ARGS__)
#define _glGetCombinerOutputParameterivNVProcPtr(...) \
    callWithGLCheck(glGetCombinerOutputParameterivNVProcPtr, __VA_ARGS__)
#define _glGetCombinerStageParameterfvNV(...) \
    callWithGLCheck(glGetCombinerStageParameterfvNV, __VA_ARGS__)
#define _glGetCombinerStageParameterfvNVProcPtr(...) \
    callWithGLCheck(glGetCombinerStageParameterfvNVProcPtr, __VA_ARGS__)
#define _glGetCompressedTexImageARB(...) \
    callWithGLCheck(glGetCompressedTexImageARB, __VA_ARGS__)
#define _glGetCompressedTexImageARBProcPtr(...) \
    callWithGLCheck(glGetCompressedTexImageARBProcPtr, __VA_ARGS__)
#define _glGetConvolutionFilterEXT(...) \
    callWithGLCheck(glGetConvolutionFilterEXT, __VA_ARGS__)
#define _glGetConvolutionFilterEXTProcPtr(...) \
    callWithGLCheck(glGetConvolutionFilterEXTProcPtr, __VA_ARGS__)
#define _glGetConvolutionParameterfvEXT(...) \
    callWithGLCheck(glGetConvolutionParameterfvEXT, __VA_ARGS__)
#define _glGetConvolutionParameterfvEXTProcPtr(...) \
    callWithGLCheck(glGetConvolutionParameterfvEXTProcPtr, __VA_ARGS__)
#define _glGetConvolutionParameterivEXT(...) \
    callWithGLCheck(glGetConvolutionParameterivEXT, __VA_ARGS__)
#define _glGetConvolutionParameterivEXTProcPtr(...) \
    callWithGLCheck(glGetConvolutionParameterivEXTProcPtr, __VA_ARGS__)
#define _glGetFinalCombinerInputParameterfvNV(...) \
    callWithGLCheck(glGetFinalCombinerInputParameterfvNV, __VA_ARGS__)
#define _glGetFinalCombinerInputParameterfvNVProcPtr(...) \
    callWithGLCheck(glGetFinalCombinerInputParameterfvNVProcPtr, __VA_ARGS__)
#define _glGetFinalCombinerInputParameterivNV(...) \
    callWithGLCheck(glGetFinalCombinerInputParameterivNV, __VA_ARGS__)
#define _glGetFinalCombinerInputParameterivNVProcPtr(...) \
    callWithGLCheck(glGetFinalCombinerInputParameterivNVProcPtr, __VA_ARGS__)
#define _glGetFragDataLocationEXT(...) \
    callWithGLCheck(glGetFragDataLocationEXT, __VA_ARGS__)
#define _glGetFragDataLocationEXTProcPtr(...) \
    callWithGLCheck(glGetFragDataLocationEXTProcPtr, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameteriv(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameteriv, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameterivEXT(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameterivEXT, __VA_ARGS__)
#define _glGetFramebufferAttachmentParameterivEXTProcPtr(...)        \
    callWithGLCheck(glGetFramebufferAttachmentParameterivEXTProcPtr, \
                    __VA_ARGS__)
#define _glGetFramebufferAttachmentParameterivProcPtr(...) \
    callWithGLCheck(glGetFramebufferAttachmentParameterivProcPtr, __VA_ARGS__)
#define _glGetHandleARB(...) callWithGLCheck(glGetHandleARB, __VA_ARGS__)
#define _glGetHandleARBProcPtr(...) \
    callWithGLCheck(glGetHandleARBProcPtr, __VA_ARGS__)
#define _glGetHistogramEXT(...) callWithGLCheck(glGetHistogramEXT, __VA_ARGS__)
#define _glGetHistogramEXTProcPtr(...) \
    callWithGLCheck(glGetHistogramEXTProcPtr, __VA_ARGS__)
#define _glGetHistogramParameterfvEXT(...) \
    callWithGLCheck(glGetHistogramParameterfvEXT, __VA_ARGS__)
#define _glGetHistogramParameterfvEXTProcPtr(...) \
    callWithGLCheck(glGetHistogramParameterfvEXTProcPtr, __VA_ARGS__)
#define _glGetHistogramParameterivEXT(...) \
    callWithGLCheck(glGetHistogramParameterivEXT, __VA_ARGS__)
#define _glGetHistogramParameterivEXTProcPtr(...) \
    callWithGLCheck(glGetHistogramParameterivEXTProcPtr, __VA_ARGS__)
#define _glGetInfoLogARB(...) callWithGLCheck(glGetInfoLogARB, __VA_ARGS__)
#define _glGetInfoLogARBProcPtr(...) \
    callWithGLCheck(glGetInfoLogARBProcPtr, __VA_ARGS__)
#define _glGetInteger64v(...) callWithGLCheck(glGetInteger64v, __VA_ARGS__)
#define _glGetInteger64vProcPtr(...) \
    callWithGLCheck(glGetInteger64vProcPtr, __VA_ARGS__)
#define _glGetIntegerIndexedvEXT(...) \
    callWithGLCheck(glGetIntegerIndexedvEXT, __VA_ARGS__)
#define _glGetIntegerIndexedvEXTProcPtr(...) \
    callWithGLCheck(glGetIntegerIndexedvEXTProcPtr, __VA_ARGS__)
#define _glGetMinmaxEXT(...) callWithGLCheck(glGetMinmaxEXT, __VA_ARGS__)
#define _glGetMinmaxEXTProcPtr(...) \
    callWithGLCheck(glGetMinmaxEXTProcPtr, __VA_ARGS__)
#define _glGetMinmaxParameterfvEXT(...) \
    callWithGLCheck(glGetMinmaxParameterfvEXT, __VA_ARGS__)
#define _glGetMinmaxParameterfvEXTProcPtr(...) \
    callWithGLCheck(glGetMinmaxParameterfvEXTProcPtr, __VA_ARGS__)
#define _glGetMinmaxParameterivEXT(...) \
    callWithGLCheck(glGetMinmaxParameterivEXT, __VA_ARGS__)
#define _glGetMinmaxParameterivEXTProcPtr(...) \
    callWithGLCheck(glGetMinmaxParameterivEXTProcPtr, __VA_ARGS__)
#define _glGetObjectLabelEXT(...) \
    callWithGLCheck(glGetObjectLabelEXT, __VA_ARGS__)
#define _glGetObjectLabelEXTProcPtr(...) \
    callWithGLCheck(glGetObjectLabelEXTProcPtr, __VA_ARGS__)
#define _glGetObjectParameterfvARB(...) \
    callWithGLCheck(glGetObjectParameterfvARB, __VA_ARGS__)
#define _glGetObjectParameterfvARBProcPtr(...) \
    callWithGLCheck(glGetObjectParameterfvARBProcPtr, __VA_ARGS__)
#define _glGetObjectParameterivAPPLE(...) \
    callWithGLCheck(glGetObjectParameterivAPPLE, __VA_ARGS__)
#define _glGetObjectParameterivAPPLEProcPtr(...) \
    callWithGLCheck(glGetObjectParameterivAPPLEProcPtr, __VA_ARGS__)
#define _glGetObjectParameterivARB(...) \
    callWithGLCheck(glGetObjectParameterivARB, __VA_ARGS__)
#define _glGetObjectParameterivARBProcPtr(...) \
    callWithGLCheck(glGetObjectParameterivARBProcPtr, __VA_ARGS__)
#define _glGetPointervEXT(...) callWithGLCheck(glGetPointervEXT, __VA_ARGS__)
#define _glGetPointervEXTProcPtr(...) \
    callWithGLCheck(glGetPointervEXTProcPtr, __VA_ARGS__)
#define _glGetProgramEnvParameterdvARB(...) \
    callWithGLCheck(glGetProgramEnvParameterdvARB, __VA_ARGS__)
#define _glGetProgramEnvParameterdvARBProcPtr(...) \
    callWithGLCheck(glGetProgramEnvParameterdvARBProcPtr, __VA_ARGS__)
#define _glGetProgramEnvParameterfvARB(...) \
    callWithGLCheck(glGetProgramEnvParameterfvARB, __VA_ARGS__)
#define _glGetProgramEnvParameterfvARBProcPtr(...) \
    callWithGLCheck(glGetProgramEnvParameterfvARBProcPtr, __VA_ARGS__)
#define _glGetProgramLocalParameterdvARB(...) \
    callWithGLCheck(glGetProgramLocalParameterdvARB, __VA_ARGS__)
#define _glGetProgramLocalParameterdvARBProcPtr(...) \
    callWithGLCheck(glGetProgramLocalParameterdvARBProcPtr, __VA_ARGS__)
#define _glGetProgramLocalParameterfvARB(...) \
    callWithGLCheck(glGetProgramLocalParameterfvARB, __VA_ARGS__)
#define _glGetProgramLocalParameterfvARBProcPtr(...) \
    callWithGLCheck(glGetProgramLocalParameterfvARBProcPtr, __VA_ARGS__)
#define _glGetProgramParameterdvNV(...) \
    callWithGLCheck(glGetProgramParameterdvNV, __VA_ARGS__)
#define _glGetProgramParameterdvNVProcPtr(...) \
    callWithGLCheck(glGetProgramParameterdvNVProcPtr, __VA_ARGS__)
#define _glGetProgramParameterfvNV(...) \
    callWithGLCheck(glGetProgramParameterfvNV, __VA_ARGS__)
#define _glGetProgramParameterfvNVProcPtr(...) \
    callWithGLCheck(glGetProgramParameterfvNVProcPtr, __VA_ARGS__)
#define _glGetProgramStringARB(...) \
    callWithGLCheck(glGetProgramStringARB, __VA_ARGS__)
#define _glGetProgramStringARBProcPtr(...) \
    callWithGLCheck(glGetProgramStringARBProcPtr, __VA_ARGS__)
#define _glGetProgramStringNV(...) \
    callWithGLCheck(glGetProgramStringNV, __VA_ARGS__)
#define _glGetProgramStringNVProcPtr(...) \
    callWithGLCheck(glGetProgramStringNVProcPtr, __VA_ARGS__)
#define _glGetProgramivARB(...) callWithGLCheck(glGetProgramivARB, __VA_ARGS__)
#define _glGetProgramivARBProcPtr(...) \
    callWithGLCheck(glGetProgramivARBProcPtr, __VA_ARGS__)
#define _glGetProgramivNV(...) callWithGLCheck(glGetProgramivNV, __VA_ARGS__)
#define _glGetProgramivNVProcPtr(...) \
    callWithGLCheck(glGetProgramivNVProcPtr, __VA_ARGS__)
#define _glGetQueryObjecti64vEXT(...) \
    callWithGLCheck(glGetQueryObjecti64vEXT, __VA_ARGS__)
#define _glGetQueryObjecti64vEXTProcPtr(...) \
    callWithGLCheck(glGetQueryObjecti64vEXTProcPtr, __VA_ARGS__)
#define _glGetQueryObjectivARB(...) \
    callWithGLCheck(glGetQueryObjectivARB, __VA_ARGS__)
#define _glGetQueryObjectivARBProcPtr(...) \
    callWithGLCheck(glGetQueryObjectivARBProcPtr, __VA_ARGS__)
#define _glGetQueryObjectui64vEXT(...) \
    callWithGLCheck(glGetQueryObjectui64vEXT, __VA_ARGS__)
#define _glGetQueryObjectui64vEXTProcPtr(...) \
    callWithGLCheck(glGetQueryObjectui64vEXTProcPtr, __VA_ARGS__)
#define _glGetQueryObjectuivARB(...) \
    callWithGLCheck(glGetQueryObjectuivARB, __VA_ARGS__)
#define _glGetQueryObjectuivARBProcPtr(...) \
    callWithGLCheck(glGetQueryObjectuivARBProcPtr, __VA_ARGS__)
#define _glGetQueryivARB(...) callWithGLCheck(glGetQueryivARB, __VA_ARGS__)
#define _glGetQueryivARBProcPtr(...) \
    callWithGLCheck(glGetQueryivARBProcPtr, __VA_ARGS__)
#define _glGetRenderbufferParameteriv(...) \
    callWithGLCheck(glGetRenderbufferParameteriv, __VA_ARGS__)
#define _glGetRenderbufferParameterivEXT(...) \
    callWithGLCheck(glGetRenderbufferParameterivEXT, __VA_ARGS__)
#define _glGetRenderbufferParameterivEXTProcPtr(...) \
    callWithGLCheck(glGetRenderbufferParameterivEXTProcPtr, __VA_ARGS__)
#define _glGetRenderbufferParameterivProcPtr(...) \
    callWithGLCheck(glGetRenderbufferParameterivProcPtr, __VA_ARGS__)
#define _glGetSeparableFilterEXT(...) \
    callWithGLCheck(glGetSeparableFilterEXT, __VA_ARGS__)
#define _glGetSeparableFilterEXTProcPtr(...) \
    callWithGLCheck(glGetSeparableFilterEXTProcPtr, __VA_ARGS__)
#define _glGetShaderSourceARB(...) \
    callWithGLCheck(glGetShaderSourceARB, __VA_ARGS__)
#define _glGetShaderSourceARBProcPtr(...) \
    callWithGLCheck(glGetShaderSourceARBProcPtr, __VA_ARGS__)
#define _glGetSynciv(...) callWithGLCheck(glGetSynciv, __VA_ARGS__)
#define _glGetSyncivProcPtr(...) \
    callWithGLCheck(glGetSyncivProcPtr, __VA_ARGS__)
#define _glGetTexParameterIivEXT(...) \
    callWithGLCheck(glGetTexParameterIivEXT, __VA_ARGS__)
#define _glGetTexParameterIivEXTProcPtr(...) \
    callWithGLCheck(glGetTexParameterIivEXTProcPtr, __VA_ARGS__)
#define _glGetTexParameterIuivEXT(...) \
    callWithGLCheck(glGetTexParameterIuivEXT, __VA_ARGS__)
#define _glGetTexParameterIuivEXTProcPtr(...) \
    callWithGLCheck(glGetTexParameterIuivEXTProcPtr, __VA_ARGS__)
#define _glGetTexParameterPointervAPPLE(...) \
    callWithGLCheck(glGetTexParameterPointervAPPLE, __VA_ARGS__)
#define _glGetTexParameterPointervAPPLEProcPtr(...) \
    callWithGLCheck(glGetTexParameterPointervAPPLEProcPtr, __VA_ARGS__)
#define _glGetTrackMatrixivNV(...) \
    callWithGLCheck(glGetTrackMatrixivNV, __VA_ARGS__)
#define _glGetTrackMatrixivNVProcPtr(...) \
    callWithGLCheck(glGetTrackMatrixivNVProcPtr, __VA_ARGS__)
#define _glGetTransformFeedbackVaryingEXT(...) \
    callWithGLCheck(glGetTransformFeedbackVaryingEXT, __VA_ARGS__)
#define _glGetTransformFeedbackVaryingEXTProcPtr(...) \
    callWithGLCheck(glGetTransformFeedbackVaryingEXTProcPtr, __VA_ARGS__)
#define _glGetUniformBufferSizeEXT(...) \
    callWithGLCheck(glGetUniformBufferSizeEXT, __VA_ARGS__)
#define _glGetUniformBufferSizeEXTProcPtr(...) \
    callWithGLCheck(glGetUniformBufferSizeEXTProcPtr, __VA_ARGS__)
#define _glGetUniformLocationARB(...) \
    callWithGLCheck(glGetUniformLocationARB, __VA_ARGS__)
#define _glGetUniformLocationARBProcPtr(...) \
    callWithGLCheck(glGetUniformLocationARBProcPtr, __VA_ARGS__)
#define _glGetUniformOffsetEXT(...) \
    callWithGLCheck(glGetUniformOffsetEXT, __VA_ARGS__)
#define _glGetUniformOffsetEXTProcPtr(...) \
    callWithGLCheck(glGetUniformOffsetEXTProcPtr, __VA_ARGS__)
#define _glGetUniformfvARB(...) callWithGLCheck(glGetUniformfvARB, __VA_ARGS__)
#define _glGetUniformfvARBProcPtr(...) \
    callWithGLCheck(glGetUniformfvARBProcPtr, __VA_ARGS__)
#define _glGetUniformivARB(...) callWithGLCheck(glGetUniformivARB, __VA_ARGS__)
#define _glGetUniformivARBProcPtr(...) \
    callWithGLCheck(glGetUniformivARBProcPtr, __VA_ARGS__)
#define _glGetUniformuivEXT(...) \
    callWithGLCheck(glGetUniformuivEXT, __VA_ARGS__)
#define _glGetUniformuivEXTProcPtr(...) \
    callWithGLCheck(glGetUniformuivEXTProcPtr, __VA_ARGS__)
#define _glGetVertexAttribIivEXT(...) \
    callWithGLCheck(glGetVertexAttribIivEXT, __VA_ARGS__)
#define _glGetVertexAttribIivEXTProcPtr(...) \
    callWithGLCheck(glGetVertexAttribIivEXTProcPtr, __VA_ARGS__)
#define _glGetVertexAttribIuivEXT(...) \
    callWithGLCheck(glGetVertexAttribIuivEXT, __VA_ARGS__)
#define _glGetVertexAttribIuivEXTProcPtr(...) \
    callWithGLCheck(glGetVertexAttribIuivEXTProcPtr, __VA_ARGS__)
#define _glGetVertexAttribPointervARB(...) \
    callWithGLCheck(glGetVertexAttribPointervARB, __VA_ARGS__)
#define _glGetVertexAttribPointervARBProcPtr(...) \
    callWithGLCheck(glGetVertexAttribPointervARBProcPtr, __VA_ARGS__)
#define _glGetVertexAttribPointervNV(...) \
    callWithGLCheck(glGetVertexAttribPointervNV, __VA_ARGS__)
#define _glGetVertexAttribPointervNVProcPtr(...) \
    callWithGLCheck(glGetVertexAttribPointervNVProcPtr, __VA_ARGS__)
#define _glGetVertexAttribdvARB(...) \
    callWithGLCheck(glGetVertexAttribdvARB, __VA_ARGS__)
#define _glGetVertexAttribdvARBProcPtr(...) \
    callWithGLCheck(glGetVertexAttribdvARBProcPtr, __VA_ARGS__)
#define _glGetVertexAttribdvNV(...) \
    callWithGLCheck(glGetVertexAttribdvNV, __VA_ARGS__)
#define _glGetVertexAttribdvNVProcPtr(...) \
    callWithGLCheck(glGetVertexAttribdvNVProcPtr, __VA_ARGS__)
#define _glGetVertexAttribfvARB(...) \
    callWithGLCheck(glGetVertexAttribfvARB, __VA_ARGS__)
#define _glGetVertexAttribfvARBProcPtr(...) \
    callWithGLCheck(glGetVertexAttribfvARBProcPtr, __VA_ARGS__)
#define _glGetVertexAttribfvNV(...) \
    callWithGLCheck(glGetVertexAttribfvNV, __VA_ARGS__)
#define _glGetVertexAttribfvNVProcPtr(...) \
    callWithGLCheck(glGetVertexAttribfvNVProcPtr, __VA_ARGS__)
#define _glGetVertexAttribivARB(...) \
    callWithGLCheck(glGetVertexAttribivARB, __VA_ARGS__)
#define _glGetVertexAttribivARBProcPtr(...) \
    callWithGLCheck(glGetVertexAttribivARBProcPtr, __VA_ARGS__)
#define _glGetVertexAttribivNV(...) \
    callWithGLCheck(glGetVertexAttribivNV, __VA_ARGS__)
#define _glGetVertexAttribivNVProcPtr(...) \
    callWithGLCheck(glGetVertexAttribivNVProcPtr, __VA_ARGS__)
#define _glHistogramEXT(...) callWithGLCheck(glHistogramEXT, __VA_ARGS__)
#define _glHistogramEXTProcPtr(...) \
    callWithGLCheck(glHistogramEXTProcPtr, __VA_ARGS__)
#define _glIndexPointerEXT(...) callWithGLCheck(glIndexPointerEXT, __VA_ARGS__)
#define _glIndexPointerEXTProcPtr(...) \
    callWithGLCheck(glIndexPointerEXTProcPtr, __VA_ARGS__)
#define _glInsertEventMarkerEXT(...) \
    callWithGLCheck(glInsertEventMarkerEXT, __VA_ARGS__)
#define _glInsertEventMarkerEXTProcPtr(...) \
    callWithGLCheck(glInsertEventMarkerEXTProcPtr, __VA_ARGS__)
#define _glIsBufferARB(...) callWithGLCheck(glIsBufferARB, __VA_ARGS__)
#define _glIsBufferARBProcPtr(...) \
    callWithGLCheck(glIsBufferARBProcPtr, __VA_ARGS__)
#define _glIsEnabledIndexedEXT(...) \
    callWithGLCheck(glIsEnabledIndexedEXT, __VA_ARGS__)
#define _glIsEnabledIndexedEXTProcPtr(...) \
    callWithGLCheck(glIsEnabledIndexedEXTProcPtr, __VA_ARGS__)
#define _glIsFenceAPPLE(...) callWithGLCheck(glIsFenceAPPLE, __VA_ARGS__)
#define _glIsFenceAPPLEProcPtr(...) \
    callWithGLCheck(glIsFenceAPPLEProcPtr, __VA_ARGS__)
#define _glIsFramebuffer(...) callWithGLCheck(glIsFramebuffer, __VA_ARGS__)
#define _glIsFramebufferEXT(...) \
    callWithGLCheck(glIsFramebufferEXT, __VA_ARGS__)
#define _glIsFramebufferEXTProcPtr(...) \
    callWithGLCheck(glIsFramebufferEXTProcPtr, __VA_ARGS__)
#define _glIsFramebufferProcPtr(...) \
    callWithGLCheck(glIsFramebufferProcPtr, __VA_ARGS__)
#define _glIsProgramARB(...) callWithGLCheck(glIsProgramARB, __VA_ARGS__)
#define _glIsProgramARBProcPtr(...) \
    callWithGLCheck(glIsProgramARBProcPtr, __VA_ARGS__)
#define _glIsProgramNV(...) callWithGLCheck(glIsProgramNV, __VA_ARGS__)
#define _glIsProgramNVProcPtr(...) \
    callWithGLCheck(glIsProgramNVProcPtr, __VA_ARGS__)
#define _glIsQueryARB(...) callWithGLCheck(glIsQueryARB, __VA_ARGS__)
#define _glIsQueryARBProcPtr(...) \
    callWithGLCheck(glIsQueryARBProcPtr, __VA_ARGS__)
#define _glIsRenderbuffer(...) callWithGLCheck(glIsRenderbuffer, __VA_ARGS__)
#define _glIsRenderbufferEXT(...) \
    callWithGLCheck(glIsRenderbufferEXT, __VA_ARGS__)
#define _glIsRenderbufferEXTProcPtr(...) \
    callWithGLCheck(glIsRenderbufferEXTProcPtr, __VA_ARGS__)
#define _glIsRenderbufferProcPtr(...) \
    callWithGLCheck(glIsRenderbufferProcPtr, __VA_ARGS__)
#define _glIsSync(...) callWithGLCheck(glIsSync, __VA_ARGS__)
#define _glIsSyncProcPtr(...) callWithGLCheck(glIsSyncProcPtr, __VA_ARGS__)
#define _glIsTextureEXT(...) callWithGLCheck(glIsTextureEXT, __VA_ARGS__)
#define _glIsTextureEXTProcPtr(...) \
    callWithGLCheck(glIsTextureEXTProcPtr, __VA_ARGS__)
#define _glIsVertexArrayAPPLE(...) \
    callWithGLCheck(glIsVertexArrayAPPLE, __VA_ARGS__)
#define _glIsVertexArrayAPPLEProcPtr(...) \
    callWithGLCheck(glIsVertexArrayAPPLEProcPtr, __VA_ARGS__)
#define _glIsVertexAttribEnabledAPPLE(...) \
    callWithGLCheck(glIsVertexAttribEnabledAPPLE, __VA_ARGS__)
#define _glIsVertexAttribEnabledAPPLEProcPtr(...) \
    callWithGLCheck(glIsVertexAttribEnabledAPPLEProcPtr, __VA_ARGS__)
#define _glLabelObjectEXT(...) callWithGLCheck(glLabelObjectEXT, __VA_ARGS__)
#define _glLabelObjectEXTProcPtr(...) \
    callWithGLCheck(glLabelObjectEXTProcPtr, __VA_ARGS__)
#define _glLinkProgramARB(...) callWithGLCheck(glLinkProgramARB, __VA_ARGS__)
#define _glLinkProgramARBProcPtr(...) \
    callWithGLCheck(glLinkProgramARBProcPtr, __VA_ARGS__)
#define _glLoadProgramNV(...) callWithGLCheck(glLoadProgramNV, __VA_ARGS__)
#define _glLoadProgramNVProcPtr(...) \
    callWithGLCheck(glLoadProgramNVProcPtr, __VA_ARGS__)
#define _glLoadTransposeMatrixdARB(...) \
    callWithGLCheck(glLoadTransposeMatrixdARB, __VA_ARGS__)
#define _glLoadTransposeMatrixdARBProcPtr(...) \
    callWithGLCheck(glLoadTransposeMatrixdARBProcPtr, __VA_ARGS__)
#define _glLoadTransposeMatrixfARB(...) \
    callWithGLCheck(glLoadTransposeMatrixfARB, __VA_ARGS__)
#define _glLoadTransposeMatrixfARBProcPtr(...) \
    callWithGLCheck(glLoadTransposeMatrixfARBProcPtr, __VA_ARGS__)
#define _glLockArraysEXT(...) callWithGLCheck(glLockArraysEXT, __VA_ARGS__)
#define _glLockArraysEXTProcPtr(...) \
    callWithGLCheck(glLockArraysEXTProcPtr, __VA_ARGS__)
#define _glMapBufferARB(...) callWithGLCheck(glMapBufferARB, __VA_ARGS__)
#define _glMapBufferARBProcPtr(...) \
    callWithGLCheck(glMapBufferARBProcPtr, __VA_ARGS__)
#define _glMapVertexAttrib1dAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib1dAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib1dAPPLEProcPtr(...) \
    callWithGLCheck(glMapVertexAttrib1dAPPLEProcPtr, __VA_ARGS__)
#define _glMapVertexAttrib1fAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib1fAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib1fAPPLEProcPtr(...) \
    callWithGLCheck(glMapVertexAttrib1fAPPLEProcPtr, __VA_ARGS__)
#define _glMapVertexAttrib2dAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib2dAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib2dAPPLEProcPtr(...) \
    callWithGLCheck(glMapVertexAttrib2dAPPLEProcPtr, __VA_ARGS__)
#define _glMapVertexAttrib2fAPPLE(...) \
    callWithGLCheck(glMapVertexAttrib2fAPPLE, __VA_ARGS__)
#define _glMapVertexAttrib2fAPPLEProcPtr(...) \
    callWithGLCheck(glMapVertexAttrib2fAPPLEProcPtr, __VA_ARGS__)
#define _glMinmaxEXT(...) callWithGLCheck(glMinmaxEXT, __VA_ARGS__)
#define _glMinmaxEXTProcPtr(...) \
    callWithGLCheck(glMinmaxEXTProcPtr, __VA_ARGS__)
#define _glMultTransposeMatrixdARB(...) \
    callWithGLCheck(glMultTransposeMatrixdARB, __VA_ARGS__)
#define _glMultTransposeMatrixdARBProcPtr(...) \
    callWithGLCheck(glMultTransposeMatrixdARBProcPtr, __VA_ARGS__)
#define _glMultTransposeMatrixfARB(...) \
    callWithGLCheck(glMultTransposeMatrixfARB, __VA_ARGS__)
#define _glMultTransposeMatrixfARBProcPtr(...) \
    callWithGLCheck(glMultTransposeMatrixfARBProcPtr, __VA_ARGS__)
#define _glMultiDrawArraysEXT(...) \
    callWithGLCheck(glMultiDrawArraysEXT, __VA_ARGS__)
#define _glMultiDrawArraysEXTProcPtr(...) \
    callWithGLCheck(glMultiDrawArraysEXTProcPtr, __VA_ARGS__)
#define _glMultiDrawElementArrayAPPLE(...) \
    callWithGLCheck(glMultiDrawElementArrayAPPLE, __VA_ARGS__)
#define _glMultiDrawElementArrayAPPLEProcPtr(...) \
    callWithGLCheck(glMultiDrawElementArrayAPPLEProcPtr, __VA_ARGS__)
#define _glMultiDrawElementsBaseVertex(...) \
    callWithGLCheck(glMultiDrawElementsBaseVertex, __VA_ARGS__)
#define _glMultiDrawElementsBaseVertexProcPtr(...) \
    callWithGLCheck(glMultiDrawElementsBaseVertexProcPtr, __VA_ARGS__)
#define _glMultiDrawElementsEXT(...) \
    callWithGLCheck(glMultiDrawElementsEXT, __VA_ARGS__)
#define _glMultiDrawElementsEXTProcPtr(...) \
    callWithGLCheck(glMultiDrawElementsEXTProcPtr, __VA_ARGS__)
#define _glMultiDrawRangeElementArrayAPPLE(...) \
    callWithGLCheck(glMultiDrawRangeElementArrayAPPLE, __VA_ARGS__)
#define _glMultiDrawRangeElementArrayAPPLEProcPtr(...) \
    callWithGLCheck(glMultiDrawRangeElementArrayAPPLEProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1dARB(...) \
    callWithGLCheck(glMultiTexCoord1dARB, __VA_ARGS__)
#define _glMultiTexCoord1dARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1dARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1dvARB(...) \
    callWithGLCheck(glMultiTexCoord1dvARB, __VA_ARGS__)
#define _glMultiTexCoord1dvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1dvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1fARB(...) \
    callWithGLCheck(glMultiTexCoord1fARB, __VA_ARGS__)
#define _glMultiTexCoord1fARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1fARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1fvARB(...) \
    callWithGLCheck(glMultiTexCoord1fvARB, __VA_ARGS__)
#define _glMultiTexCoord1fvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1fvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1iARB(...) \
    callWithGLCheck(glMultiTexCoord1iARB, __VA_ARGS__)
#define _glMultiTexCoord1iARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1iARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1ivARB(...) \
    callWithGLCheck(glMultiTexCoord1ivARB, __VA_ARGS__)
#define _glMultiTexCoord1ivARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1ivARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1sARB(...) \
    callWithGLCheck(glMultiTexCoord1sARB, __VA_ARGS__)
#define _glMultiTexCoord1sARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1sARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord1svARB(...) \
    callWithGLCheck(glMultiTexCoord1svARB, __VA_ARGS__)
#define _glMultiTexCoord1svARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord1svARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2dARB(...) \
    callWithGLCheck(glMultiTexCoord2dARB, __VA_ARGS__)
#define _glMultiTexCoord2dARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2dARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2dvARB(...) \
    callWithGLCheck(glMultiTexCoord2dvARB, __VA_ARGS__)
#define _glMultiTexCoord2dvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2dvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2fARB(...) \
    callWithGLCheck(glMultiTexCoord2fARB, __VA_ARGS__)
#define _glMultiTexCoord2fARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2fARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2fvARB(...) \
    callWithGLCheck(glMultiTexCoord2fvARB, __VA_ARGS__)
#define _glMultiTexCoord2fvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2fvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2iARB(...) \
    callWithGLCheck(glMultiTexCoord2iARB, __VA_ARGS__)
#define _glMultiTexCoord2iARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2iARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2ivARB(...) \
    callWithGLCheck(glMultiTexCoord2ivARB, __VA_ARGS__)
#define _glMultiTexCoord2ivARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2ivARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2sARB(...) \
    callWithGLCheck(glMultiTexCoord2sARB, __VA_ARGS__)
#define _glMultiTexCoord2sARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2sARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord2svARB(...) \
    callWithGLCheck(glMultiTexCoord2svARB, __VA_ARGS__)
#define _glMultiTexCoord2svARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord2svARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3dARB(...) \
    callWithGLCheck(glMultiTexCoord3dARB, __VA_ARGS__)
#define _glMultiTexCoord3dARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3dARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3dvARB(...) \
    callWithGLCheck(glMultiTexCoord3dvARB, __VA_ARGS__)
#define _glMultiTexCoord3dvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3dvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3fARB(...) \
    callWithGLCheck(glMultiTexCoord3fARB, __VA_ARGS__)
#define _glMultiTexCoord3fARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3fARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3fvARB(...) \
    callWithGLCheck(glMultiTexCoord3fvARB, __VA_ARGS__)
#define _glMultiTexCoord3fvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3fvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3iARB(...) \
    callWithGLCheck(glMultiTexCoord3iARB, __VA_ARGS__)
#define _glMultiTexCoord3iARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3iARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3ivARB(...) \
    callWithGLCheck(glMultiTexCoord3ivARB, __VA_ARGS__)
#define _glMultiTexCoord3ivARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3ivARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3sARB(...) \
    callWithGLCheck(glMultiTexCoord3sARB, __VA_ARGS__)
#define _glMultiTexCoord3sARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3sARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord3svARB(...) \
    callWithGLCheck(glMultiTexCoord3svARB, __VA_ARGS__)
#define _glMultiTexCoord3svARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord3svARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4dARB(...) \
    callWithGLCheck(glMultiTexCoord4dARB, __VA_ARGS__)
#define _glMultiTexCoord4dARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4dARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4dvARB(...) \
    callWithGLCheck(glMultiTexCoord4dvARB, __VA_ARGS__)
#define _glMultiTexCoord4dvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4dvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4fARB(...) \
    callWithGLCheck(glMultiTexCoord4fARB, __VA_ARGS__)
#define _glMultiTexCoord4fARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4fARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4fvARB(...) \
    callWithGLCheck(glMultiTexCoord4fvARB, __VA_ARGS__)
#define _glMultiTexCoord4fvARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4fvARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4iARB(...) \
    callWithGLCheck(glMultiTexCoord4iARB, __VA_ARGS__)
#define _glMultiTexCoord4iARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4iARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4ivARB(...) \
    callWithGLCheck(glMultiTexCoord4ivARB, __VA_ARGS__)
#define _glMultiTexCoord4ivARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4ivARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4sARB(...) \
    callWithGLCheck(glMultiTexCoord4sARB, __VA_ARGS__)
#define _glMultiTexCoord4sARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4sARBProcPtr, __VA_ARGS__)
#define _glMultiTexCoord4svARB(...) \
    callWithGLCheck(glMultiTexCoord4svARB, __VA_ARGS__)
#define _glMultiTexCoord4svARBProcPtr(...) \
    callWithGLCheck(glMultiTexCoord4svARBProcPtr, __VA_ARGS__)
#define _glNormalPointerEXT(...) \
    callWithGLCheck(glNormalPointerEXT, __VA_ARGS__)
#define _glNormalPointerEXTProcPtr(...) \
    callWithGLCheck(glNormalPointerEXTProcPtr, __VA_ARGS__)
#define _glObjectPurgeableAPPLE(...) \
    callWithGLCheck(glObjectPurgeableAPPLE, __VA_ARGS__)
#define _glObjectPurgeableAPPLEProcPtr(...) \
    callWithGLCheck(glObjectPurgeableAPPLEProcPtr, __VA_ARGS__)
#define _glObjectUnpurgeableAPPLE(...) \
    callWithGLCheck(glObjectUnpurgeableAPPLE, __VA_ARGS__)
#define _glObjectUnpurgeableAPPLEProcPtr(...) \
    callWithGLCheck(glObjectUnpurgeableAPPLEProcPtr, __VA_ARGS__)
#define _glPNTrianglesfATI(...) callWithGLCheck(glPNTrianglesfATI, __VA_ARGS__)
#define _glPNTrianglesfATIProcPtr(...) \
    callWithGLCheck(glPNTrianglesfATIProcPtr, __VA_ARGS__)
#define _glPNTrianglesfATIX(...) \
    callWithGLCheck(glPNTrianglesfATIX, __VA_ARGS__)
#define _glPNTrianglesfATIXProcPtr(...) \
    callWithGLCheck(glPNTrianglesfATIXProcPtr, __VA_ARGS__)
#define _glPNTrianglesiATI(...) callWithGLCheck(glPNTrianglesiATI, __VA_ARGS__)
#define _glPNTrianglesiATIProcPtr(...) \
    callWithGLCheck(glPNTrianglesiATIProcPtr, __VA_ARGS__)
#define _glPNTrianglesiATIX(...) \
    callWithGLCheck(glPNTrianglesiATIX, __VA_ARGS__)
#define _glPNTrianglesiATIXProcPtr(...) \
    callWithGLCheck(glPNTrianglesiATIXProcPtr, __VA_ARGS__)
#define _glPointParameterfARB(...) \
    callWithGLCheck(glPointParameterfARB, __VA_ARGS__)
#define _glPointParameterfARBProcPtr(...) \
    callWithGLCheck(glPointParameterfARBProcPtr, __VA_ARGS__)
#define _glPointParameterfvARB(...) \
    callWithGLCheck(glPointParameterfvARB, __VA_ARGS__)
#define _glPointParameterfvARBProcPtr(...) \
    callWithGLCheck(glPointParameterfvARBProcPtr, __VA_ARGS__)
#define _glPointParameteriNV(...) \
    callWithGLCheck(glPointParameteriNV, __VA_ARGS__)
#define _glPointParameteriNVProcPtr(...) \
    callWithGLCheck(glPointParameteriNVProcPtr, __VA_ARGS__)
#define _glPointParameterivNV(...) \
    callWithGLCheck(glPointParameterivNV, __VA_ARGS__)
#define _glPointParameterivNVProcPtr(...) \
    callWithGLCheck(glPointParameterivNVProcPtr, __VA_ARGS__)
#define _glPointSizePointerAPPLE(...) \
    callWithGLCheck(glPointSizePointerAPPLE, __VA_ARGS__)
#define _glPointSizePointerAPPLEProcPtr(...) \
    callWithGLCheck(glPointSizePointerAPPLEProcPtr, __VA_ARGS__)
#define _glPolygonOffsetEXT(...) \
    callWithGLCheck(glPolygonOffsetEXT, __VA_ARGS__)
#define _glPolygonOffsetEXTProcPtr(...) \
    callWithGLCheck(glPolygonOffsetEXTProcPtr, __VA_ARGS__)
#define _glPopGroupMarkerEXT(...) \
    callWithGLCheck(glPopGroupMarkerEXT, __VA_ARGS__)
#define _glPopGroupMarkerEXTProcPtr(...) \
    callWithGLCheck(glPopGroupMarkerEXTProcPtr, __VA_ARGS__)
#define _glPrioritizeTexturesEXT(...) \
    callWithGLCheck(glPrioritizeTexturesEXT, __VA_ARGS__)
#define _glPrioritizeTexturesEXTProcPtr(...) \
    callWithGLCheck(glPrioritizeTexturesEXTProcPtr, __VA_ARGS__)
#define _glProgramEnvParameter4dARB(...) \
    callWithGLCheck(glProgramEnvParameter4dARB, __VA_ARGS__)
#define _glProgramEnvParameter4dARBProcPtr(...) \
    callWithGLCheck(glProgramEnvParameter4dARBProcPtr, __VA_ARGS__)
#define _glProgramEnvParameter4dvARB(...) \
    callWithGLCheck(glProgramEnvParameter4dvARB, __VA_ARGS__)
#define _glProgramEnvParameter4dvARBProcPtr(...) \
    callWithGLCheck(glProgramEnvParameter4dvARBProcPtr, __VA_ARGS__)
#define _glProgramEnvParameter4fARB(...) \
    callWithGLCheck(glProgramEnvParameter4fARB, __VA_ARGS__)
#define _glProgramEnvParameter4fARBProcPtr(...) \
    callWithGLCheck(glProgramEnvParameter4fARBProcPtr, __VA_ARGS__)
#define _glProgramEnvParameter4fvARB(...) \
    callWithGLCheck(glProgramEnvParameter4fvARB, __VA_ARGS__)
#define _glProgramEnvParameter4fvARBProcPtr(...) \
    callWithGLCheck(glProgramEnvParameter4fvARBProcPtr, __VA_ARGS__)
#define _glProgramEnvParameters4fvEXT(...) \
    callWithGLCheck(glProgramEnvParameters4fvEXT, __VA_ARGS__)
#define _glProgramEnvParameters4fvEXTProcPtr(...) \
    callWithGLCheck(glProgramEnvParameters4fvEXTProcPtr, __VA_ARGS__)
#define _glProgramLocalParameter4dARB(...) \
    callWithGLCheck(glProgramLocalParameter4dARB, __VA_ARGS__)
#define _glProgramLocalParameter4dARBProcPtr(...) \
    callWithGLCheck(glProgramLocalParameter4dARBProcPtr, __VA_ARGS__)
#define _glProgramLocalParameter4dvARB(...) \
    callWithGLCheck(glProgramLocalParameter4dvARB, __VA_ARGS__)
#define _glProgramLocalParameter4dvARBProcPtr(...) \
    callWithGLCheck(glProgramLocalParameter4dvARBProcPtr, __VA_ARGS__)
#define _glProgramLocalParameter4fARB(...) \
    callWithGLCheck(glProgramLocalParameter4fARB, __VA_ARGS__)
#define _glProgramLocalParameter4fARBProcPtr(...) \
    callWithGLCheck(glProgramLocalParameter4fARBProcPtr, __VA_ARGS__)
#define _glProgramLocalParameter4fvARB(...) \
    callWithGLCheck(glProgramLocalParameter4fvARB, __VA_ARGS__)
#define _glProgramLocalParameter4fvARBProcPtr(...) \
    callWithGLCheck(glProgramLocalParameter4fvARBProcPtr, __VA_ARGS__)
#define _glProgramLocalParameters4fvEXT(...) \
    callWithGLCheck(glProgramLocalParameters4fvEXT, __VA_ARGS__)
#define _glProgramLocalParameters4fvEXTProcPtr(...) \
    callWithGLCheck(glProgramLocalParameters4fvEXTProcPtr, __VA_ARGS__)
#define _glProgramParameter4dNV(...) \
    callWithGLCheck(glProgramParameter4dNV, __VA_ARGS__)
#define _glProgramParameter4dNVProcPtr(...) \
    callWithGLCheck(glProgramParameter4dNVProcPtr, __VA_ARGS__)
#define _glProgramParameter4dvNV(...) \
    callWithGLCheck(glProgramParameter4dvNV, __VA_ARGS__)
#define _glProgramParameter4dvNVProcPtr(...) \
    callWithGLCheck(glProgramParameter4dvNVProcPtr, __VA_ARGS__)
#define _glProgramParameter4fNV(...) \
    callWithGLCheck(glProgramParameter4fNV, __VA_ARGS__)
#define _glProgramParameter4fNVProcPtr(...) \
    callWithGLCheck(glProgramParameter4fNVProcPtr, __VA_ARGS__)
#define _glProgramParameter4fvNV(...) \
    callWithGLCheck(glProgramParameter4fvNV, __VA_ARGS__)
#define _glProgramParameter4fvNVProcPtr(...) \
    callWithGLCheck(glProgramParameter4fvNVProcPtr, __VA_ARGS__)
#define _glProgramParameteriEXT(...) \
    callWithGLCheck(glProgramParameteriEXT, __VA_ARGS__)
#define _glProgramParameteriEXTProcPtr(...) \
    callWithGLCheck(glProgramParameteriEXTProcPtr, __VA_ARGS__)
#define _glProgramParameters4dvNV(...) \
    callWithGLCheck(glProgramParameters4dvNV, __VA_ARGS__)
#define _glProgramParameters4dvNVProcPtr(...) \
    callWithGLCheck(glProgramParameters4dvNVProcPtr, __VA_ARGS__)
#define _glProgramParameters4fvNV(...) \
    callWithGLCheck(glProgramParameters4fvNV, __VA_ARGS__)
#define _glProgramParameters4fvNVProcPtr(...) \
    callWithGLCheck(glProgramParameters4fvNVProcPtr, __VA_ARGS__)
#define _glProgramStringARB(...) \
    callWithGLCheck(glProgramStringARB, __VA_ARGS__)
#define _glProgramStringARBProcPtr(...) \
    callWithGLCheck(glProgramStringARBProcPtr, __VA_ARGS__)
#define _glProvokingVertex(...) callWithGLCheck(glProvokingVertex, __VA_ARGS__)
#define _glProvokingVertexEXT(...) \
    callWithGLCheck(glProvokingVertexEXT, __VA_ARGS__)
#define _glProvokingVertexEXTProcPtr(...) \
    callWithGLCheck(glProvokingVertexEXTProcPtr, __VA_ARGS__)
#define _glProvokingVertexProcPtr(...) \
    callWithGLCheck(glProvokingVertexProcPtr, __VA_ARGS__)
#define _glPushGroupMarkerEXT(...) \
    callWithGLCheck(glPushGroupMarkerEXT, __VA_ARGS__)
#define _glPushGroupMarkerEXTProcPtr(...) \
    callWithGLCheck(glPushGroupMarkerEXTProcPtr, __VA_ARGS__)
#define _glRenderbufferStorage(...) \
    callWithGLCheck(glRenderbufferStorage, __VA_ARGS__)
#define _glRenderbufferStorageEXT(...) \
    callWithGLCheck(glRenderbufferStorageEXT, __VA_ARGS__)
#define _glRenderbufferStorageEXTProcPtr(...) \
    callWithGLCheck(glRenderbufferStorageEXTProcPtr, __VA_ARGS__)
#define _glRenderbufferStorageMultisample(...) \
    callWithGLCheck(glRenderbufferStorageMultisample, __VA_ARGS__)
#define _glRenderbufferStorageMultisampleEXT(...) \
    callWithGLCheck(glRenderbufferStorageMultisampleEXT, __VA_ARGS__)
#define _glRenderbufferStorageMultisampleEXTProcPtr(...) \
    callWithGLCheck(glRenderbufferStorageMultisampleEXTProcPtr, __VA_ARGS__)
#define _glRenderbufferStorageMultisampleProcPtr(...) \
    callWithGLCheck(glRenderbufferStorageMultisampleProcPtr, __VA_ARGS__)
#define _glRenderbufferStorageProcPtr(...) \
    callWithGLCheck(glRenderbufferStorageProcPtr, __VA_ARGS__)
#define _glRequestResidentProgramsNV(...) \
    callWithGLCheck(glRequestResidentProgramsNV, __VA_ARGS__)
#define _glRequestResidentProgramsNVProcPtr(...) \
    callWithGLCheck(glRequestResidentProgramsNVProcPtr, __VA_ARGS__)
#define _glResetHistogramEXT(...) \
    callWithGLCheck(glResetHistogramEXT, __VA_ARGS__)
#define _glResetHistogramEXTProcPtr(...) \
    callWithGLCheck(glResetHistogramEXTProcPtr, __VA_ARGS__)
#define _glResetMinmaxEXT(...) callWithGLCheck(glResetMinmaxEXT, __VA_ARGS__)
#define _glResetMinmaxEXTProcPtr(...) \
    callWithGLCheck(glResetMinmaxEXTProcPtr, __VA_ARGS__)
#define _glSampleCoverageARB(...) \
    callWithGLCheck(glSampleCoverageARB, __VA_ARGS__)
#define _glSampleCoverageARBProcPtr(...) \
    callWithGLCheck(glSampleCoverageARBProcPtr, __VA_ARGS__)
#define _glSecondaryColor3bEXT(...) \
    callWithGLCheck(glSecondaryColor3bEXT, __VA_ARGS__)
#define _glSecondaryColor3bEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3bEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3bvEXT(...) \
    callWithGLCheck(glSecondaryColor3bvEXT, __VA_ARGS__)
#define _glSecondaryColor3bvEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3bvEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3dEXT(...) \
    callWithGLCheck(glSecondaryColor3dEXT, __VA_ARGS__)
#define _glSecondaryColor3dEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3dEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3dvEXT(...) \
    callWithGLCheck(glSecondaryColor3dvEXT, __VA_ARGS__)
#define _glSecondaryColor3dvEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3dvEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3fEXT(...) \
    callWithGLCheck(glSecondaryColor3fEXT, __VA_ARGS__)
#define _glSecondaryColor3fEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3fEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3fvEXT(...) \
    callWithGLCheck(glSecondaryColor3fvEXT, __VA_ARGS__)
#define _glSecondaryColor3fvEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3fvEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3iEXT(...) \
    callWithGLCheck(glSecondaryColor3iEXT, __VA_ARGS__)
#define _glSecondaryColor3iEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3iEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ivEXT(...) \
    callWithGLCheck(glSecondaryColor3ivEXT, __VA_ARGS__)
#define _glSecondaryColor3ivEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ivEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3sEXT(...) \
    callWithGLCheck(glSecondaryColor3sEXT, __VA_ARGS__)
#define _glSecondaryColor3sEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3sEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3svEXT(...) \
    callWithGLCheck(glSecondaryColor3svEXT, __VA_ARGS__)
#define _glSecondaryColor3svEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3svEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ubEXT(...) \
    callWithGLCheck(glSecondaryColor3ubEXT, __VA_ARGS__)
#define _glSecondaryColor3ubEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ubEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3ubvEXT(...) \
    callWithGLCheck(glSecondaryColor3ubvEXT, __VA_ARGS__)
#define _glSecondaryColor3ubvEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3ubvEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3uiEXT(...) \
    callWithGLCheck(glSecondaryColor3uiEXT, __VA_ARGS__)
#define _glSecondaryColor3uiEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3uiEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3uivEXT(...) \
    callWithGLCheck(glSecondaryColor3uivEXT, __VA_ARGS__)
#define _glSecondaryColor3uivEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3uivEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3usEXT(...) \
    callWithGLCheck(glSecondaryColor3usEXT, __VA_ARGS__)
#define _glSecondaryColor3usEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3usEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColor3usvEXT(...) \
    callWithGLCheck(glSecondaryColor3usvEXT, __VA_ARGS__)
#define _glSecondaryColor3usvEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColor3usvEXTProcPtr, __VA_ARGS__)
#define _glSecondaryColorPointerEXT(...) \
    callWithGLCheck(glSecondaryColorPointerEXT, __VA_ARGS__)
#define _glSecondaryColorPointerEXTProcPtr(...) \
    callWithGLCheck(glSecondaryColorPointerEXTProcPtr, __VA_ARGS__)
#define _glSeparableFilter2DEXT(...) \
    callWithGLCheck(glSeparableFilter2DEXT, __VA_ARGS__)
#define _glSeparableFilter2DEXTProcPtr(...) \
    callWithGLCheck(glSeparableFilter2DEXTProcPtr, __VA_ARGS__)
#define _glSetFenceAPPLE(...) callWithGLCheck(glSetFenceAPPLE, __VA_ARGS__)
#define _glSetFenceAPPLEProcPtr(...) \
    callWithGLCheck(glSetFenceAPPLEProcPtr, __VA_ARGS__)
#define _glShaderSourceARB(...) callWithGLCheck(glShaderSourceARB, __VA_ARGS__)
#define _glShaderSourceARBProcPtr(...) \
    callWithGLCheck(glShaderSourceARBProcPtr, __VA_ARGS__)
#define _glStencilFuncSeparateATI(...) \
    callWithGLCheck(glStencilFuncSeparateATI, __VA_ARGS__)
#define _glStencilFuncSeparateATIProcPtr(...) \
    callWithGLCheck(glStencilFuncSeparateATIProcPtr, __VA_ARGS__)
#define _glStencilOpSeparateATI(...) \
    callWithGLCheck(glStencilOpSeparateATI, __VA_ARGS__)
#define _glStencilOpSeparateATIProcPtr(...) \
    callWithGLCheck(glStencilOpSeparateATIProcPtr, __VA_ARGS__)
#define _glSwapAPPLE(...) callWithGLCheck(glSwapAPPLE, __VA_ARGS__)
#define _glSwapAPPLEProcPtr(...) \
    callWithGLCheck(glSwapAPPLEProcPtr, __VA_ARGS__)
#define _glTestFenceAPPLE(...) callWithGLCheck(glTestFenceAPPLE, __VA_ARGS__)
#define _glTestFenceAPPLEProcPtr(...) \
    callWithGLCheck(glTestFenceAPPLEProcPtr, __VA_ARGS__)
#define _glTestObjectAPPLE(...) callWithGLCheck(glTestObjectAPPLE, __VA_ARGS__)
#define _glTestObjectAPPLEProcPtr(...) \
    callWithGLCheck(glTestObjectAPPLEProcPtr, __VA_ARGS__)
#define _glTexCoordPointerEXT(...) \
    callWithGLCheck(glTexCoordPointerEXT, __VA_ARGS__)
#define _glTexCoordPointerEXTProcPtr(...) \
    callWithGLCheck(glTexCoordPointerEXTProcPtr, __VA_ARGS__)
#define _glTexImage3DEXT(...) callWithGLCheck(glTexImage3DEXT, __VA_ARGS__)
#define _glTexImage3DEXTProcPtr(...) \
    callWithGLCheck(glTexImage3DEXTProcPtr, __VA_ARGS__)
#define _glTexParameterIivEXT(...) \
    callWithGLCheck(glTexParameterIivEXT, __VA_ARGS__)
#define _glTexParameterIivEXTProcPtr(...) \
    callWithGLCheck(glTexParameterIivEXTProcPtr, __VA_ARGS__)
#define _glTexParameterIuivEXT(...) \
    callWithGLCheck(glTexParameterIuivEXT, __VA_ARGS__)
#define _glTexParameterIuivEXTProcPtr(...) \
    callWithGLCheck(glTexParameterIuivEXTProcPtr, __VA_ARGS__)
#define _glTexSubImage1DEXT(...) \
    callWithGLCheck(glTexSubImage1DEXT, __VA_ARGS__)
#define _glTexSubImage1DEXTProcPtr(...) \
    callWithGLCheck(glTexSubImage1DEXTProcPtr, __VA_ARGS__)
#define _glTexSubImage2DEXT(...) \
    callWithGLCheck(glTexSubImage2DEXT, __VA_ARGS__)
#define _glTexSubImage2DEXTProcPtr(...) \
    callWithGLCheck(glTexSubImage2DEXTProcPtr, __VA_ARGS__)
#define _glTexSubImage3DEXT(...) \
    callWithGLCheck(glTexSubImage3DEXT, __VA_ARGS__)
#define _glTexSubImage3DEXTProcPtr(...) \
    callWithGLCheck(glTexSubImage3DEXTProcPtr, __VA_ARGS__)
#define _glTextureBarrierNV(...) \
    callWithGLCheck(glTextureBarrierNV, __VA_ARGS__)
#define _glTextureBarrierNVProcPtr(...) \
    callWithGLCheck(glTextureBarrierNVProcPtr, __VA_ARGS__)
#define _glTextureRangeAPPLE(...) \
    callWithGLCheck(glTextureRangeAPPLE, __VA_ARGS__)
#define _glTextureRangeAPPLEProcPtr(...) \
    callWithGLCheck(glTextureRangeAPPLEProcPtr, __VA_ARGS__)
#define _glTrackMatrixNV(...) callWithGLCheck(glTrackMatrixNV, __VA_ARGS__)
#define _glTrackMatrixNVProcPtr(...) \
    callWithGLCheck(glTrackMatrixNVProcPtr, __VA_ARGS__)
#define _glTransformFeedbackVaryingsEXT(...) \
    callWithGLCheck(glTransformFeedbackVaryingsEXT, __VA_ARGS__)
#define _glTransformFeedbackVaryingsEXTProcPtr(...) \
    callWithGLCheck(glTransformFeedbackVaryingsEXTProcPtr, __VA_ARGS__)
#define _glUniform1fARB(...) callWithGLCheck(glUniform1fARB, __VA_ARGS__)
#define _glUniform1fARBProcPtr(...) \
    callWithGLCheck(glUniform1fARBProcPtr, __VA_ARGS__)
#define _glUniform1fvARB(...) callWithGLCheck(glUniform1fvARB, __VA_ARGS__)
#define _glUniform1fvARBProcPtr(...) \
    callWithGLCheck(glUniform1fvARBProcPtr, __VA_ARGS__)
#define _glUniform1iARB(...) callWithGLCheck(glUniform1iARB, __VA_ARGS__)
#define _glUniform1iARBProcPtr(...) \
    callWithGLCheck(glUniform1iARBProcPtr, __VA_ARGS__)
#define _glUniform1ivARB(...) callWithGLCheck(glUniform1ivARB, __VA_ARGS__)
#define _glUniform1ivARBProcPtr(...) \
    callWithGLCheck(glUniform1ivARBProcPtr, __VA_ARGS__)
#define _glUniform1uiEXT(...) callWithGLCheck(glUniform1uiEXT, __VA_ARGS__)
#define _glUniform1uiEXTProcPtr(...) \
    callWithGLCheck(glUniform1uiEXTProcPtr, __VA_ARGS__)
#define _glUniform1uivEXT(...) callWithGLCheck(glUniform1uivEXT, __VA_ARGS__)
#define _glUniform1uivEXTProcPtr(...) \
    callWithGLCheck(glUniform1uivEXTProcPtr, __VA_ARGS__)
#define _glUniform2fARB(...) callWithGLCheck(glUniform2fARB, __VA_ARGS__)
#define _glUniform2fARBProcPtr(...) \
    callWithGLCheck(glUniform2fARBProcPtr, __VA_ARGS__)
#define _glUniform2fvARB(...) callWithGLCheck(glUniform2fvARB, __VA_ARGS__)
#define _glUniform2fvARBProcPtr(...) \
    callWithGLCheck(glUniform2fvARBProcPtr, __VA_ARGS__)
#define _glUniform2iARB(...) callWithGLCheck(glUniform2iARB, __VA_ARGS__)
#define _glUniform2iARBProcPtr(...) \
    callWithGLCheck(glUniform2iARBProcPtr, __VA_ARGS__)
#define _glUniform2ivARB(...) callWithGLCheck(glUniform2ivARB, __VA_ARGS__)
#define _glUniform2ivARBProcPtr(...) \
    callWithGLCheck(glUniform2ivARBProcPtr, __VA_ARGS__)
#define _glUniform2uiEXT(...) callWithGLCheck(glUniform2uiEXT, __VA_ARGS__)
#define _glUniform2uiEXTProcPtr(...) \
    callWithGLCheck(glUniform2uiEXTProcPtr, __VA_ARGS__)
#define _glUniform2uivEXT(...) callWithGLCheck(glUniform2uivEXT, __VA_ARGS__)
#define _glUniform2uivEXTProcPtr(...) \
    callWithGLCheck(glUniform2uivEXTProcPtr, __VA_ARGS__)
#define _glUniform3fARB(...) callWithGLCheck(glUniform3fARB, __VA_ARGS__)
#define _glUniform3fARBProcPtr(...) \
    callWithGLCheck(glUniform3fARBProcPtr, __VA_ARGS__)
#define _glUniform3fvARB(...) callWithGLCheck(glUniform3fvARB, __VA_ARGS__)
#define _glUniform3fvARBProcPtr(...) \
    callWithGLCheck(glUniform3fvARBProcPtr, __VA_ARGS__)
#define _glUniform3iARB(...) callWithGLCheck(glUniform3iARB, __VA_ARGS__)
#define _glUniform3iARBProcPtr(...) \
    callWithGLCheck(glUniform3iARBProcPtr, __VA_ARGS__)
#define _glUniform3ivARB(...) callWithGLCheck(glUniform3ivARB, __VA_ARGS__)
#define _glUniform3ivARBProcPtr(...) \
    callWithGLCheck(glUniform3ivARBProcPtr, __VA_ARGS__)
#define _glUniform3uiEXT(...) callWithGLCheck(glUniform3uiEXT, __VA_ARGS__)
#define _glUniform3uiEXTProcPtr(...) \
    callWithGLCheck(glUniform3uiEXTProcPtr, __VA_ARGS__)
#define _glUniform3uivEXT(...) callWithGLCheck(glUniform3uivEXT, __VA_ARGS__)
#define _glUniform3uivEXTProcPtr(...) \
    callWithGLCheck(glUniform3uivEXTProcPtr, __VA_ARGS__)
#define _glUniform4fARB(...) callWithGLCheck(glUniform4fARB, __VA_ARGS__)
#define _glUniform4fARBProcPtr(...) \
    callWithGLCheck(glUniform4fARBProcPtr, __VA_ARGS__)
#define _glUniform4fvARB(...) callWithGLCheck(glUniform4fvARB, __VA_ARGS__)
#define _glUniform4fvARBProcPtr(...) \
    callWithGLCheck(glUniform4fvARBProcPtr, __VA_ARGS__)
#define _glUniform4iARB(...) callWithGLCheck(glUniform4iARB, __VA_ARGS__)
#define _glUniform4iARBProcPtr(...) \
    callWithGLCheck(glUniform4iARBProcPtr, __VA_ARGS__)
#define _glUniform4ivARB(...) callWithGLCheck(glUniform4ivARB, __VA_ARGS__)
#define _glUniform4ivARBProcPtr(...) \
    callWithGLCheck(glUniform4ivARBProcPtr, __VA_ARGS__)
#define _glUniform4uiEXT(...) callWithGLCheck(glUniform4uiEXT, __VA_ARGS__)
#define _glUniform4uiEXTProcPtr(...) \
    callWithGLCheck(glUniform4uiEXTProcPtr, __VA_ARGS__)
#define _glUniform4uivEXT(...) callWithGLCheck(glUniform4uivEXT, __VA_ARGS__)
#define _glUniform4uivEXTProcPtr(...) \
    callWithGLCheck(glUniform4uivEXTProcPtr, __VA_ARGS__)
#define _glUniformBufferEXT(...) \
    callWithGLCheck(glUniformBufferEXT, __VA_ARGS__)
#define _glUniformBufferEXTProcPtr(...) \
    callWithGLCheck(glUniformBufferEXTProcPtr, __VA_ARGS__)
#define _glUniformMatrix2fvARB(...) \
    callWithGLCheck(glUniformMatrix2fvARB, __VA_ARGS__)
#define _glUniformMatrix2fvARBProcPtr(...) \
    callWithGLCheck(glUniformMatrix2fvARBProcPtr, __VA_ARGS__)
#define _glUniformMatrix3fvARB(...) \
    callWithGLCheck(glUniformMatrix3fvARB, __VA_ARGS__)
#define _glUniformMatrix3fvARBProcPtr(...) \
    callWithGLCheck(glUniformMatrix3fvARBProcPtr, __VA_ARGS__)
#define _glUniformMatrix4fvARB(...) \
    callWithGLCheck(glUniformMatrix4fvARB, __VA_ARGS__)
#define _glUniformMatrix4fvARBProcPtr(...) \
    callWithGLCheck(glUniformMatrix4fvARBProcPtr, __VA_ARGS__)
#define _glUnlockArraysEXT(...) callWithGLCheck(glUnlockArraysEXT, __VA_ARGS__)
#define _glUnlockArraysEXTProcPtr(...) \
    callWithGLCheck(glUnlockArraysEXTProcPtr, __VA_ARGS__)
#define _glUnmapBufferARB(...) callWithGLCheck(glUnmapBufferARB, __VA_ARGS__)
#define _glUnmapBufferARBProcPtr(...) \
    callWithGLCheck(glUnmapBufferARBProcPtr, __VA_ARGS__)
#define _glUseProgramObjectARB(...) \
    callWithGLCheck(glUseProgramObjectARB, __VA_ARGS__)
#define _glUseProgramObjectARBProcPtr(...) \
    callWithGLCheck(glUseProgramObjectARBProcPtr, __VA_ARGS__)
#define _glValidateProgramARB(...) \
    callWithGLCheck(glValidateProgramARB, __VA_ARGS__)
#define _glValidateProgramARBProcPtr(...) \
    callWithGLCheck(glValidateProgramARBProcPtr, __VA_ARGS__)
#define _glVertexArrayParameteriAPPLE(...) \
    callWithGLCheck(glVertexArrayParameteriAPPLE, __VA_ARGS__)
#define _glVertexArrayParameteriAPPLEProcPtr(...) \
    callWithGLCheck(glVertexArrayParameteriAPPLEProcPtr, __VA_ARGS__)
#define _glVertexArrayRangeAPPLE(...) \
    callWithGLCheck(glVertexArrayRangeAPPLE, __VA_ARGS__)
#define _glVertexArrayRangeAPPLEProcPtr(...) \
    callWithGLCheck(glVertexArrayRangeAPPLEProcPtr, __VA_ARGS__)
#define _glVertexArrayRangeNV(...) \
    callWithGLCheck(glVertexArrayRangeNV, __VA_ARGS__)
#define _glVertexArrayRangeNVProcPtr(...) \
    callWithGLCheck(glVertexArrayRangeNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1dARB(...) \
    callWithGLCheck(glVertexAttrib1dARB, __VA_ARGS__)
#define _glVertexAttrib1dARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1dNV(...) \
    callWithGLCheck(glVertexAttrib1dNV, __VA_ARGS__)
#define _glVertexAttrib1dNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1dvARB(...) \
    callWithGLCheck(glVertexAttrib1dvARB, __VA_ARGS__)
#define _glVertexAttrib1dvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1dvNV(...) \
    callWithGLCheck(glVertexAttrib1dvNV, __VA_ARGS__)
#define _glVertexAttrib1dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1fARB(...) \
    callWithGLCheck(glVertexAttrib1fARB, __VA_ARGS__)
#define _glVertexAttrib1fARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1fNV(...) \
    callWithGLCheck(glVertexAttrib1fNV, __VA_ARGS__)
#define _glVertexAttrib1fNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1fvARB(...) \
    callWithGLCheck(glVertexAttrib1fvARB, __VA_ARGS__)
#define _glVertexAttrib1fvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1fvNV(...) \
    callWithGLCheck(glVertexAttrib1fvNV, __VA_ARGS__)
#define _glVertexAttrib1fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1sARB(...) \
    callWithGLCheck(glVertexAttrib1sARB, __VA_ARGS__)
#define _glVertexAttrib1sARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1sARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1sNV(...) \
    callWithGLCheck(glVertexAttrib1sNV, __VA_ARGS__)
#define _glVertexAttrib1sNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1sNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib1svARB(...) \
    callWithGLCheck(glVertexAttrib1svARB, __VA_ARGS__)
#define _glVertexAttrib1svARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib1svARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib1svNV(...) \
    callWithGLCheck(glVertexAttrib1svNV, __VA_ARGS__)
#define _glVertexAttrib1svNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib1svNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2dARB(...) \
    callWithGLCheck(glVertexAttrib2dARB, __VA_ARGS__)
#define _glVertexAttrib2dARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2dNV(...) \
    callWithGLCheck(glVertexAttrib2dNV, __VA_ARGS__)
#define _glVertexAttrib2dNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2dvARB(...) \
    callWithGLCheck(glVertexAttrib2dvARB, __VA_ARGS__)
#define _glVertexAttrib2dvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2dvNV(...) \
    callWithGLCheck(glVertexAttrib2dvNV, __VA_ARGS__)
#define _glVertexAttrib2dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2fARB(...) \
    callWithGLCheck(glVertexAttrib2fARB, __VA_ARGS__)
#define _glVertexAttrib2fARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2fNV(...) \
    callWithGLCheck(glVertexAttrib2fNV, __VA_ARGS__)
#define _glVertexAttrib2fNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2fvARB(...) \
    callWithGLCheck(glVertexAttrib2fvARB, __VA_ARGS__)
#define _glVertexAttrib2fvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2fvNV(...) \
    callWithGLCheck(glVertexAttrib2fvNV, __VA_ARGS__)
#define _glVertexAttrib2fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2sARB(...) \
    callWithGLCheck(glVertexAttrib2sARB, __VA_ARGS__)
#define _glVertexAttrib2sARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2sARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2sNV(...) \
    callWithGLCheck(glVertexAttrib2sNV, __VA_ARGS__)
#define _glVertexAttrib2sNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2sNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib2svARB(...) \
    callWithGLCheck(glVertexAttrib2svARB, __VA_ARGS__)
#define _glVertexAttrib2svARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib2svARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib2svNV(...) \
    callWithGLCheck(glVertexAttrib2svNV, __VA_ARGS__)
#define _glVertexAttrib2svNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib2svNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3dARB(...) \
    callWithGLCheck(glVertexAttrib3dARB, __VA_ARGS__)
#define _glVertexAttrib3dARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3dNV(...) \
    callWithGLCheck(glVertexAttrib3dNV, __VA_ARGS__)
#define _glVertexAttrib3dNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3dvARB(...) \
    callWithGLCheck(glVertexAttrib3dvARB, __VA_ARGS__)
#define _glVertexAttrib3dvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3dvNV(...) \
    callWithGLCheck(glVertexAttrib3dvNV, __VA_ARGS__)
#define _glVertexAttrib3dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3fARB(...) \
    callWithGLCheck(glVertexAttrib3fARB, __VA_ARGS__)
#define _glVertexAttrib3fARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3fNV(...) \
    callWithGLCheck(glVertexAttrib3fNV, __VA_ARGS__)
#define _glVertexAttrib3fNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3fvARB(...) \
    callWithGLCheck(glVertexAttrib3fvARB, __VA_ARGS__)
#define _glVertexAttrib3fvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3fvNV(...) \
    callWithGLCheck(glVertexAttrib3fvNV, __VA_ARGS__)
#define _glVertexAttrib3fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3sARB(...) \
    callWithGLCheck(glVertexAttrib3sARB, __VA_ARGS__)
#define _glVertexAttrib3sARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3sARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3sNV(...) \
    callWithGLCheck(glVertexAttrib3sNV, __VA_ARGS__)
#define _glVertexAttrib3sNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3sNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib3svARB(...) \
    callWithGLCheck(glVertexAttrib3svARB, __VA_ARGS__)
#define _glVertexAttrib3svARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib3svARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib3svNV(...) \
    callWithGLCheck(glVertexAttrib3svNV, __VA_ARGS__)
#define _glVertexAttrib3svNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib3svNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NbvARB(...) \
    callWithGLCheck(glVertexAttrib4NbvARB, __VA_ARGS__)
#define _glVertexAttrib4NbvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NbvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NivARB(...) \
    callWithGLCheck(glVertexAttrib4NivARB, __VA_ARGS__)
#define _glVertexAttrib4NivARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NivARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NsvARB(...) \
    callWithGLCheck(glVertexAttrib4NsvARB, __VA_ARGS__)
#define _glVertexAttrib4NsvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NsvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NubARB(...) \
    callWithGLCheck(glVertexAttrib4NubARB, __VA_ARGS__)
#define _glVertexAttrib4NubARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NubARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NubvARB(...) \
    callWithGLCheck(glVertexAttrib4NubvARB, __VA_ARGS__)
#define _glVertexAttrib4NubvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NubvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NuivARB(...) \
    callWithGLCheck(glVertexAttrib4NuivARB, __VA_ARGS__)
#define _glVertexAttrib4NuivARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NuivARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4NusvARB(...) \
    callWithGLCheck(glVertexAttrib4NusvARB, __VA_ARGS__)
#define _glVertexAttrib4NusvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4NusvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4bvARB(...) \
    callWithGLCheck(glVertexAttrib4bvARB, __VA_ARGS__)
#define _glVertexAttrib4bvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4bvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4dARB(...) \
    callWithGLCheck(glVertexAttrib4dARB, __VA_ARGS__)
#define _glVertexAttrib4dARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4dNV(...) \
    callWithGLCheck(glVertexAttrib4dNV, __VA_ARGS__)
#define _glVertexAttrib4dNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4dvARB(...) \
    callWithGLCheck(glVertexAttrib4dvARB, __VA_ARGS__)
#define _glVertexAttrib4dvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4dvNV(...) \
    callWithGLCheck(glVertexAttrib4dvNV, __VA_ARGS__)
#define _glVertexAttrib4dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4fARB(...) \
    callWithGLCheck(glVertexAttrib4fARB, __VA_ARGS__)
#define _glVertexAttrib4fARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4fNV(...) \
    callWithGLCheck(glVertexAttrib4fNV, __VA_ARGS__)
#define _glVertexAttrib4fNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4fvARB(...) \
    callWithGLCheck(glVertexAttrib4fvARB, __VA_ARGS__)
#define _glVertexAttrib4fvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4fvNV(...) \
    callWithGLCheck(glVertexAttrib4fvNV, __VA_ARGS__)
#define _glVertexAttrib4fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4ivARB(...) \
    callWithGLCheck(glVertexAttrib4ivARB, __VA_ARGS__)
#define _glVertexAttrib4ivARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ivARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4sARB(...) \
    callWithGLCheck(glVertexAttrib4sARB, __VA_ARGS__)
#define _glVertexAttrib4sARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4sARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4sNV(...) \
    callWithGLCheck(glVertexAttrib4sNV, __VA_ARGS__)
#define _glVertexAttrib4sNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4sNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4svARB(...) \
    callWithGLCheck(glVertexAttrib4svARB, __VA_ARGS__)
#define _glVertexAttrib4svARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4svARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4svNV(...) \
    callWithGLCheck(glVertexAttrib4svNV, __VA_ARGS__)
#define _glVertexAttrib4svNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4svNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4ubNV(...) \
    callWithGLCheck(glVertexAttrib4ubNV, __VA_ARGS__)
#define _glVertexAttrib4ubNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ubNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4ubvARB(...) \
    callWithGLCheck(glVertexAttrib4ubvARB, __VA_ARGS__)
#define _glVertexAttrib4ubvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ubvARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4ubvNV(...) \
    callWithGLCheck(glVertexAttrib4ubvNV, __VA_ARGS__)
#define _glVertexAttrib4ubvNVProcPtr(...) \
    callWithGLCheck(glVertexAttrib4ubvNVProcPtr, __VA_ARGS__)
#define _glVertexAttrib4uivARB(...) \
    callWithGLCheck(glVertexAttrib4uivARB, __VA_ARGS__)
#define _glVertexAttrib4uivARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4uivARBProcPtr, __VA_ARGS__)
#define _glVertexAttrib4usvARB(...) \
    callWithGLCheck(glVertexAttrib4usvARB, __VA_ARGS__)
#define _glVertexAttrib4usvARBProcPtr(...) \
    callWithGLCheck(glVertexAttrib4usvARBProcPtr, __VA_ARGS__)
#define _glVertexAttribDivisorARB(...) \
    callWithGLCheck(glVertexAttribDivisorARB, __VA_ARGS__)
#define _glVertexAttribDivisorARBProcPtr(...) \
    callWithGLCheck(glVertexAttribDivisorARBProcPtr, __VA_ARGS__)
#define _glVertexAttribI1iEXT(...) \
    callWithGLCheck(glVertexAttribI1iEXT, __VA_ARGS__)
#define _glVertexAttribI1iEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI1iEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI1ivEXT(...) \
    callWithGLCheck(glVertexAttribI1ivEXT, __VA_ARGS__)
#define _glVertexAttribI1ivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI1ivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI1uiEXT(...) \
    callWithGLCheck(glVertexAttribI1uiEXT, __VA_ARGS__)
#define _glVertexAttribI1uiEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI1uiEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI1uivEXT(...) \
    callWithGLCheck(glVertexAttribI1uivEXT, __VA_ARGS__)
#define _glVertexAttribI1uivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI1uivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI2iEXT(...) \
    callWithGLCheck(glVertexAttribI2iEXT, __VA_ARGS__)
#define _glVertexAttribI2iEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI2iEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI2ivEXT(...) \
    callWithGLCheck(glVertexAttribI2ivEXT, __VA_ARGS__)
#define _glVertexAttribI2ivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI2ivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI2uiEXT(...) \
    callWithGLCheck(glVertexAttribI2uiEXT, __VA_ARGS__)
#define _glVertexAttribI2uiEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI2uiEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI2uivEXT(...) \
    callWithGLCheck(glVertexAttribI2uivEXT, __VA_ARGS__)
#define _glVertexAttribI2uivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI2uivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI3iEXT(...) \
    callWithGLCheck(glVertexAttribI3iEXT, __VA_ARGS__)
#define _glVertexAttribI3iEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI3iEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI3ivEXT(...) \
    callWithGLCheck(glVertexAttribI3ivEXT, __VA_ARGS__)
#define _glVertexAttribI3ivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI3ivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI3uiEXT(...) \
    callWithGLCheck(glVertexAttribI3uiEXT, __VA_ARGS__)
#define _glVertexAttribI3uiEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI3uiEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI3uivEXT(...) \
    callWithGLCheck(glVertexAttribI3uivEXT, __VA_ARGS__)
#define _glVertexAttribI3uivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI3uivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4bvEXT(...) \
    callWithGLCheck(glVertexAttribI4bvEXT, __VA_ARGS__)
#define _glVertexAttribI4bvEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4bvEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4iEXT(...) \
    callWithGLCheck(glVertexAttribI4iEXT, __VA_ARGS__)
#define _glVertexAttribI4iEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4iEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4ivEXT(...) \
    callWithGLCheck(glVertexAttribI4ivEXT, __VA_ARGS__)
#define _glVertexAttribI4ivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4ivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4svEXT(...) \
    callWithGLCheck(glVertexAttribI4svEXT, __VA_ARGS__)
#define _glVertexAttribI4svEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4svEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4ubvEXT(...) \
    callWithGLCheck(glVertexAttribI4ubvEXT, __VA_ARGS__)
#define _glVertexAttribI4ubvEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4ubvEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4uiEXT(...) \
    callWithGLCheck(glVertexAttribI4uiEXT, __VA_ARGS__)
#define _glVertexAttribI4uiEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4uiEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4uivEXT(...) \
    callWithGLCheck(glVertexAttribI4uivEXT, __VA_ARGS__)
#define _glVertexAttribI4uivEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4uivEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribI4usvEXT(...) \
    callWithGLCheck(glVertexAttribI4usvEXT, __VA_ARGS__)
#define _glVertexAttribI4usvEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribI4usvEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribIPointerEXT(...) \
    callWithGLCheck(glVertexAttribIPointerEXT, __VA_ARGS__)
#define _glVertexAttribIPointerEXTProcPtr(...) \
    callWithGLCheck(glVertexAttribIPointerEXTProcPtr, __VA_ARGS__)
#define _glVertexAttribPointerARB(...) \
    callWithGLCheck(glVertexAttribPointerARB, __VA_ARGS__)
#define _glVertexAttribPointerARBProcPtr(...) \
    callWithGLCheck(glVertexAttribPointerARBProcPtr, __VA_ARGS__)
#define _glVertexAttribPointerNV(...) \
    callWithGLCheck(glVertexAttribPointerNV, __VA_ARGS__)
#define _glVertexAttribPointerNVProcPtr(...) \
    callWithGLCheck(glVertexAttribPointerNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs1dvNV(...) \
    callWithGLCheck(glVertexAttribs1dvNV, __VA_ARGS__)
#define _glVertexAttribs1dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs1dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs1fvNV(...) \
    callWithGLCheck(glVertexAttribs1fvNV, __VA_ARGS__)
#define _glVertexAttribs1fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs1fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs1svNV(...) \
    callWithGLCheck(glVertexAttribs1svNV, __VA_ARGS__)
#define _glVertexAttribs1svNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs1svNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs2dvNV(...) \
    callWithGLCheck(glVertexAttribs2dvNV, __VA_ARGS__)
#define _glVertexAttribs2dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs2dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs2fvNV(...) \
    callWithGLCheck(glVertexAttribs2fvNV, __VA_ARGS__)
#define _glVertexAttribs2fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs2fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs2svNV(...) \
    callWithGLCheck(glVertexAttribs2svNV, __VA_ARGS__)
#define _glVertexAttribs2svNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs2svNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs3dvNV(...) \
    callWithGLCheck(glVertexAttribs3dvNV, __VA_ARGS__)
#define _glVertexAttribs3dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs3dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs3fvNV(...) \
    callWithGLCheck(glVertexAttribs3fvNV, __VA_ARGS__)
#define _glVertexAttribs3fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs3fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs3svNV(...) \
    callWithGLCheck(glVertexAttribs3svNV, __VA_ARGS__)
#define _glVertexAttribs3svNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs3svNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs4dvNV(...) \
    callWithGLCheck(glVertexAttribs4dvNV, __VA_ARGS__)
#define _glVertexAttribs4dvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs4dvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs4fvNV(...) \
    callWithGLCheck(glVertexAttribs4fvNV, __VA_ARGS__)
#define _glVertexAttribs4fvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs4fvNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs4svNV(...) \
    callWithGLCheck(glVertexAttribs4svNV, __VA_ARGS__)
#define _glVertexAttribs4svNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs4svNVProcPtr, __VA_ARGS__)
#define _glVertexAttribs4ubvNV(...) \
    callWithGLCheck(glVertexAttribs4ubvNV, __VA_ARGS__)
#define _glVertexAttribs4ubvNVProcPtr(...) \
    callWithGLCheck(glVertexAttribs4ubvNVProcPtr, __VA_ARGS__)
#define _glVertexBlendARB(...) callWithGLCheck(glVertexBlendARB, __VA_ARGS__)
#define _glVertexBlendARBProcPtr(...) \
    callWithGLCheck(glVertexBlendARBProcPtr, __VA_ARGS__)
#define _glVertexPointSizefAPPLE(...) \
    callWithGLCheck(glVertexPointSizefAPPLE, __VA_ARGS__)
#define _glVertexPointSizefAPPLEProcPtr(...) \
    callWithGLCheck(glVertexPointSizefAPPLEProcPtr, __VA_ARGS__)
#define _glVertexPointerEXT(...) \
    callWithGLCheck(glVertexPointerEXT, __VA_ARGS__)
#define _glVertexPointerEXTProcPtr(...) \
    callWithGLCheck(glVertexPointerEXTProcPtr, __VA_ARGS__)
#define _glWaitSync(...) callWithGLCheck(glWaitSync, __VA_ARGS__)
#define _glWaitSyncProcPtr(...) callWithGLCheck(glWaitSyncProcPtr, __VA_ARGS__)
#define _glWeightPointerARB(...) \
    callWithGLCheck(glWeightPointerARB, __VA_ARGS__)
#define _glWeightPointerARBProcPtr(...) \
    callWithGLCheck(glWeightPointerARBProcPtr, __VA_ARGS__)
#define _glWeightbvARB(...) callWithGLCheck(glWeightbvARB, __VA_ARGS__)
#define _glWeightbvARBProcPtr(...) \
    callWithGLCheck(glWeightbvARBProcPtr, __VA_ARGS__)
#define _glWeightdvARB(...) callWithGLCheck(glWeightdvARB, __VA_ARGS__)
#define _glWeightdvARBProcPtr(...) \
    callWithGLCheck(glWeightdvARBProcPtr, __VA_ARGS__)
#define _glWeightfvARB(...) callWithGLCheck(glWeightfvARB, __VA_ARGS__)
#define _glWeightfvARBProcPtr(...) \
    callWithGLCheck(glWeightfvARBProcPtr, __VA_ARGS__)
#define _glWeightivARB(...) callWithGLCheck(glWeightivARB, __VA_ARGS__)
#define _glWeightivARBProcPtr(...) \
    callWithGLCheck(glWeightivARBProcPtr, __VA_ARGS__)
#define _glWeightsvARB(...) callWithGLCheck(glWeightsvARB, __VA_ARGS__)
#define _glWeightsvARBProcPtr(...) \
    callWithGLCheck(glWeightsvARBProcPtr, __VA_ARGS__)
#define _glWeightubvARB(...) callWithGLCheck(glWeightubvARB, __VA_ARGS__)
#define _glWeightubvARBProcPtr(...) \
    callWithGLCheck(glWeightubvARBProcPtr, __VA_ARGS__)
#define _glWeightuivARB(...) callWithGLCheck(glWeightuivARB, __VA_ARGS__)
#define _glWeightuivARBProcPtr(...) \
    callWithGLCheck(glWeightuivARBProcPtr, __VA_ARGS__)
#define _glWeightusvARB(...) callWithGLCheck(glWeightusvARB, __VA_ARGS__)
#define _glWeightusvARBProcPtr(...) \
    callWithGLCheck(glWeightusvARBProcPtr, __VA_ARGS__)
#define _glWindowPos2dARB(...) callWithGLCheck(glWindowPos2dARB, __VA_ARGS__)
#define _glWindowPos2dARBProcPtr(...) \
    callWithGLCheck(glWindowPos2dARBProcPtr, __VA_ARGS__)
#define _glWindowPos2dvARB(...) callWithGLCheck(glWindowPos2dvARB, __VA_ARGS__)
#define _glWindowPos2dvARBProcPtr(...) \
    callWithGLCheck(glWindowPos2dvARBProcPtr, __VA_ARGS__)
#define _glWindowPos2fARB(...) callWithGLCheck(glWindowPos2fARB, __VA_ARGS__)
#define _glWindowPos2fARBProcPtr(...) \
    callWithGLCheck(glWindowPos2fARBProcPtr, __VA_ARGS__)
#define _glWindowPos2fvARB(...) callWithGLCheck(glWindowPos2fvARB, __VA_ARGS__)
#define _glWindowPos2fvARBProcPtr(...) \
    callWithGLCheck(glWindowPos2fvARBProcPtr, __VA_ARGS__)
#define _glWindowPos2iARB(...) callWithGLCheck(glWindowPos2iARB, __VA_ARGS__)
#define _glWindowPos2iARBProcPtr(...) \
    callWithGLCheck(glWindowPos2iARBProcPtr, __VA_ARGS__)
#define _glWindowPos2ivARB(...) callWithGLCheck(glWindowPos2ivARB, __VA_ARGS__)
#define _glWindowPos2ivARBProcPtr(...) \
    callWithGLCheck(glWindowPos2ivARBProcPtr, __VA_ARGS__)
#define _glWindowPos2sARB(...) callWithGLCheck(glWindowPos2sARB, __VA_ARGS__)
#define _glWindowPos2sARBProcPtr(...) \
    callWithGLCheck(glWindowPos2sARBProcPtr, __VA_ARGS__)
#define _glWindowPos2svARB(...) callWithGLCheck(glWindowPos2svARB, __VA_ARGS__)
#define _glWindowPos2svARBProcPtr(...) \
    callWithGLCheck(glWindowPos2svARBProcPtr, __VA_ARGS__)
#define _glWindowPos3dARB(...) callWithGLCheck(glWindowPos3dARB, __VA_ARGS__)
#define _glWindowPos3dARBProcPtr(...) \
    callWithGLCheck(glWindowPos3dARBProcPtr, __VA_ARGS__)
#define _glWindowPos3dvARB(...) callWithGLCheck(glWindowPos3dvARB, __VA_ARGS__)
#define _glWindowPos3dvARBProcPtr(...) \
    callWithGLCheck(glWindowPos3dvARBProcPtr, __VA_ARGS__)
#define _glWindowPos3fARB(...) callWithGLCheck(glWindowPos3fARB, __VA_ARGS__)
#define _glWindowPos3fARBProcPtr(...) \
    callWithGLCheck(glWindowPos3fARBProcPtr, __VA_ARGS__)
#define _glWindowPos3fvARB(...) callWithGLCheck(glWindowPos3fvARB, __VA_ARGS__)
#define _glWindowPos3fvARBProcPtr(...) \
    callWithGLCheck(glWindowPos3fvARBProcPtr, __VA_ARGS__)
#define _glWindowPos3iARB(...) callWithGLCheck(glWindowPos3iARB, __VA_ARGS__)
#define _glWindowPos3iARBProcPtr(...) \
    callWithGLCheck(glWindowPos3iARBProcPtr, __VA_ARGS__)
#define _glWindowPos3ivARB(...) callWithGLCheck(glWindowPos3ivARB, __VA_ARGS__)
#define _glWindowPos3ivARBProcPtr(...) \
    callWithGLCheck(glWindowPos3ivARBProcPtr, __VA_ARGS__)
#define _glWindowPos3sARB(...) callWithGLCheck(glWindowPos3sARB, __VA_ARGS__)
#define _glWindowPos3sARBProcPtr(...) \
    callWithGLCheck(glWindowPos3sARBProcPtr, __VA_ARGS__)
#define _glWindowPos3svARB(...) callWithGLCheck(glWindowPos3svARB, __VA_ARGS__)
#define _glWindowPos3svARBProcPtr(...) \
    callWithGLCheck(glWindowPos3svARBProcPtr, __VA_ARGS__)
#define _glGenerateMipmap(...) callWithGLCheck(glGenerateMipmap, __VA_ARGS__)
#define _glActiveTexture(...) callWithGLCheck(glActiveTexture, __VA_ARGS__)
#define _glBeginConditionalRenderNV(...) \
    callWithGLCheck(glBeginConditionalRenderNV, __VA_ARGS__)
#define _glBeginQuery(...) callWithGLCheck(glBeginQuery, __VA_ARGS__)
#define _glBeginTransformFeedbackEXT(...) \
    callWithGLCheck(glBeginTransformFeedbackEXT, __VA_ARGS__)
#define _glBindBuffer(...) callWithGLCheck(glBindBuffer, __VA_ARGS__)
#define _glBindBufferBaseEXT(...) \
    callWithGLCheck(glBindBufferBaseEXT, __VA_ARGS__)
#define _glBindBufferRangeEXT(...) \
    callWithGLCheck(glBindBufferRangeEXT, __VA_ARGS__)
#define _glBindFragDataLocationEXT(...) \
    callWithGLCheck(glBindFragDataLocationEXT, __VA_ARGS__)
#define _glBlendColor(...) callWithGLCheck(glBlendColor, __VA_ARGS__)
#define _glBlendEquation(...) callWithGLCheck(glBlendEquation, __VA_ARGS__)
#define _glBlendEquationSeparateEXT(...) \
    callWithGLCheck(glBlendEquationSeparateEXT, __VA_ARGS__)
#define _glBlendFuncSeparate(...) \
    callWithGLCheck(glBlendFuncSeparate, __VA_ARGS__)
#define _glBufferData(...) callWithGLCheck(glBufferData, __VA_ARGS__)
#define _glBufferSubData(...) callWithGLCheck(glBufferSubData, __VA_ARGS__)
#define _glClampColorARB(...) callWithGLCheck(glClampColorARB, __VA_ARGS__)
#define _glClientActiveTexture(...) \
    callWithGLCheck(glClientActiveTexture, __VA_ARGS__)
#define _glColorMaskIndexedEXT(...) \
    callWithGLCheck(glColorMaskIndexedEXT, __VA_ARGS__)
#define _glColorSubTable(...) callWithGLCheck(glColorSubTable, __VA_ARGS__)
#define _glColorTable(...) callWithGLCheck(glColorTable, __VA_ARGS__)
#define _glCompressedTexImage1D(...) \
    callWithGLCheck(glCompressedTexImage1D, __VA_ARGS__)
#define _glCompressedTexImage2D(...) \
    callWithGLCheck(glCompressedTexImage2D, __VA_ARGS__)
#define _glCompressedTexImage3D(...) \
    callWithGLCheck(glCompressedTexImage3D, __VA_ARGS__)
#define _glCompressedTexSubImage1D(...) \
    callWithGLCheck(glCompressedTexSubImage1D, __VA_ARGS__)
#define _glCompressedTexSubImage2D(...) \
    callWithGLCheck(glCompressedTexSubImage2D, __VA_ARGS__)
#define _glCompressedTexSubImage3D(...) \
    callWithGLCheck(glCompressedTexSubImage3D, __VA_ARGS__)
#define _glDeleteBuffers(...) callWithGLCheck(glDeleteBuffers, __VA_ARGS__)
#define _glDeleteQueries(...) callWithGLCheck(glDeleteQueries, __VA_ARGS__)
#define _glDisableIndexedEXT(...) \
    callWithGLCheck(glDisableIndexedEXT, __VA_ARGS__)
#define _glDrawRangeElements(...) \
    callWithGLCheck(glDrawRangeElements, __VA_ARGS__)
#define _glEnableIndexedEXT(...) \
    callWithGLCheck(glEnableIndexedEXT, __VA_ARGS__)
#define _glEndConditionalRenderNV(...) \
    callWithGLCheck(glEndConditionalRenderNV, __VA_ARGS__)
#define _glEndQuery(...) callWithGLCheck(glEndQuery, __VA_ARGS__)
#define _glEndTransformFeedbackEXT(...) \
    callWithGLCheck(glEndTransformFeedbackEXT, __VA_ARGS__)
#define _glFlushRenderAPPLE(...) \
    callWithGLCheck(glFlushRenderAPPLE, __VA_ARGS__)
#define _glFogCoordPointer(...) callWithGLCheck(glFogCoordPointer, __VA_ARGS__)
#define _glFogCoordd(...) callWithGLCheck(glFogCoordd, __VA_ARGS__)
#define _glFogCoorddv(...) callWithGLCheck(glFogCoorddv, __VA_ARGS__)
#define _glFogCoordf(...) callWithGLCheck(glFogCoordf, __VA_ARGS__)
#define _glFogCoordfv(...) callWithGLCheck(glFogCoordfv, __VA_ARGS__)
#define _glGenBuffers(...) callWithGLCheck(glGenBuffers, __VA_ARGS__)
#define _glGenQueries(...) callWithGLCheck(glGenQueries, __VA_ARGS__)
#define _glGetBooleanIndexedvEXT(...) \
    callWithGLCheck(glGetBooleanIndexedvEXT, __VA_ARGS__)
#define _glGetBufferParameteriv(...) \
    callWithGLCheck(glGetBufferParameteriv, __VA_ARGS__)
#define _glGetBufferPointerv(...) \
    callWithGLCheck(glGetBufferPointerv, __VA_ARGS__)
#define _glGetBufferSubData(...) \
    callWithGLCheck(glGetBufferSubData, __VA_ARGS__)
#define _glGetColorTable(...) callWithGLCheck(glGetColorTable, __VA_ARGS__)
#define _glGetColorTableParameterfv(...) \
    callWithGLCheck(glGetColorTableParameterfv, __VA_ARGS__)
#define _glGetColorTableParameteriv(...) \
    callWithGLCheck(glGetColorTableParameteriv, __VA_ARGS__)
#define _glGetCompressedTexImage(...) \
    callWithGLCheck(glGetCompressedTexImage, __VA_ARGS__)
#define _glGetFragDataLocationEXT(...) \
    callWithGLCheck(glGetFragDataLocationEXT, __VA_ARGS__)
#define _glGetIntegerIndexedvEXT(...) \
    callWithGLCheck(glGetIntegerIndexedvEXT, __VA_ARGS__)
#define _glGetQueryObjectiv(...) \
    callWithGLCheck(glGetQueryObjectiv, __VA_ARGS__)
#define _glGetQueryObjectuiv(...) \
    callWithGLCheck(glGetQueryObjectuiv, __VA_ARGS__)
#define _glGetQueryiv(...) callWithGLCheck(glGetQueryiv, __VA_ARGS__)
#define _glGetTexParameterIivEXT(...) \
    callWithGLCheck(glGetTexParameterIivEXT, __VA_ARGS__)
#define _glGetTexParameterIuivEXT(...) \
    callWithGLCheck(glGetTexParameterIuivEXT, __VA_ARGS__)
#define _glGetTransformFeedbackVaryingEXT(...) \
    callWithGLCheck(glGetTransformFeedbackVaryingEXT, __VA_ARGS__)
#define _glGetUniformuivEXT(...) \
    callWithGLCheck(glGetUniformuivEXT, __VA_ARGS__)
#define _glGetVertexAttribIivEXT(...) \
    callWithGLCheck(glGetVertexAttribIivEXT, __VA_ARGS__)
#define _glGetVertexAttribIuivEXT(...) \
    callWithGLCheck(glGetVertexAttribIuivEXT, __VA_ARGS__)
#define _glIsBuffer(...) callWithGLCheck(glIsBuffer, __VA_ARGS__)
#define _glIsEnabledIndexedEXT(...) \
    callWithGLCheck(glIsEnabledIndexedEXT, __VA_ARGS__)
#define _glIsQuery(...) callWithGLCheck(glIsQuery, __VA_ARGS__)
#define _glLoadTransposeMatrixd(...) \
    callWithGLCheck(glLoadTransposeMatrixd, __VA_ARGS__)
#define _glLoadTransposeMatrixf(...) \
    callWithGLCheck(glLoadTransposeMatrixf, __VA_ARGS__)
#define _glMapBuffer(...) callWithGLCheck(glMapBuffer, __VA_ARGS__)
#define _glMultTransposeMatrixd(...) \
    callWithGLCheck(glMultTransposeMatrixd, __VA_ARGS__)
#define _glMultTransposeMatrixf(...) \
    callWithGLCheck(glMultTransposeMatrixf, __VA_ARGS__)
#define _glMultiDrawArrays(...) callWithGLCheck(glMultiDrawArrays, __VA_ARGS__)
#define _glMultiDrawElements(...) \
    callWithGLCheck(glMultiDrawElements, __VA_ARGS__)
#define _glMultiTexCoord1d(...) callWithGLCheck(glMultiTexCoord1d, __VA_ARGS__)
#define _glMultiTexCoord1dv(...) \
    callWithGLCheck(glMultiTexCoord1dv, __VA_ARGS__)
#define _glMultiTexCoord1f(...) callWithGLCheck(glMultiTexCoord1f, __VA_ARGS__)
#define _glMultiTexCoord1fv(...) \
    callWithGLCheck(glMultiTexCoord1fv, __VA_ARGS__)
#define _glMultiTexCoord1i(...) callWithGLCheck(glMultiTexCoord1i, __VA_ARGS__)
#define _glMultiTexCoord1iv(...) \
    callWithGLCheck(glMultiTexCoord1iv, __VA_ARGS__)
#define _glMultiTexCoord1s(...) callWithGLCheck(glMultiTexCoord1s, __VA_ARGS__)
#define _glMultiTexCoord1sv(...) \
    callWithGLCheck(glMultiTexCoord1sv, __VA_ARGS__)
#define _glMultiTexCoord2d(...) callWithGLCheck(glMultiTexCoord2d, __VA_ARGS__)
#define _glMultiTexCoord2dv(...) \
    callWithGLCheck(glMultiTexCoord2dv, __VA_ARGS__)
#define _glMultiTexCoord2f(...) callWithGLCheck(glMultiTexCoord2f, __VA_ARGS__)
#define _glMultiTexCoord2fv(...) \
    callWithGLCheck(glMultiTexCoord2fv, __VA_ARGS__)
#define _glMultiTexCoord2i(...) callWithGLCheck(glMultiTexCoord2i, __VA_ARGS__)
#define _glMultiTexCoord2iv(...) \
    callWithGLCheck(glMultiTexCoord2iv, __VA_ARGS__)
#define _glMultiTexCoord2s(...) callWithGLCheck(glMultiTexCoord2s, __VA_ARGS__)
#define _glMultiTexCoord2sv(...) \
    callWithGLCheck(glMultiTexCoord2sv, __VA_ARGS__)
#define _glMultiTexCoord3d(...) callWithGLCheck(glMultiTexCoord3d, __VA_ARGS__)
#define _glMultiTexCoord3dv(...) \
    callWithGLCheck(glMultiTexCoord3dv, __VA_ARGS__)
#define _glMultiTexCoord3f(...) callWithGLCheck(glMultiTexCoord3f, __VA_ARGS__)
#define _glMultiTexCoord3fv(...) \
    callWithGLCheck(glMultiTexCoord3fv, __VA_ARGS__)
#define _glMultiTexCoord3i(...) callWithGLCheck(glMultiTexCoord3i, __VA_ARGS__)
#define _glMultiTexCoord3iv(...) \
    callWithGLCheck(glMultiTexCoord3iv, __VA_ARGS__)
#define _glMultiTexCoord3s(...) callWithGLCheck(glMultiTexCoord3s, __VA_ARGS__)
#define _glMultiTexCoord3sv(...) \
    callWithGLCheck(glMultiTexCoord3sv, __VA_ARGS__)
#define _glMultiTexCoord4d(...) callWithGLCheck(glMultiTexCoord4d, __VA_ARGS__)
#define _glMultiTexCoord4dv(...) \
    callWithGLCheck(glMultiTexCoord4dv, __VA_ARGS__)
#define _glMultiTexCoord4f(...) callWithGLCheck(glMultiTexCoord4f, __VA_ARGS__)
#define _glMultiTexCoord4fv(...) \
    callWithGLCheck(glMultiTexCoord4fv, __VA_ARGS__)
#define _glMultiTexCoord4i(...) callWithGLCheck(glMultiTexCoord4i, __VA_ARGS__)
#define _glMultiTexCoord4iv(...) \
    callWithGLCheck(glMultiTexCoord4iv, __VA_ARGS__)
#define _glMultiTexCoord4s(...) callWithGLCheck(glMultiTexCoord4s, __VA_ARGS__)
#define _glMultiTexCoord4sv(...) \
    callWithGLCheck(glMultiTexCoord4sv, __VA_ARGS__)
#define _glPointParameterf(...) callWithGLCheck(glPointParameterf, __VA_ARGS__)
#define _glPointParameterfv(...) \
    callWithGLCheck(glPointParameterfv, __VA_ARGS__)
#define _glProvokingVertex(...) callWithGLCheck(glProvokingVertex, __VA_ARGS__)
#define _glSampleCoverage(...) callWithGLCheck(glSampleCoverage, __VA_ARGS__)
#define _glSecondaryColor3b(...) \
    callWithGLCheck(glSecondaryColor3b, __VA_ARGS__)
#define _glSecondaryColor3bv(...) \
    callWithGLCheck(glSecondaryColor3bv, __VA_ARGS__)
#define _glSecondaryColor3d(...) \
    callWithGLCheck(glSecondaryColor3d, __VA_ARGS__)
#define _glSecondaryColor3dv(...) \
    callWithGLCheck(glSecondaryColor3dv, __VA_ARGS__)
#define _glSecondaryColor3f(...) \
    callWithGLCheck(glSecondaryColor3f, __VA_ARGS__)
#define _glSecondaryColor3fv(...) \
    callWithGLCheck(glSecondaryColor3fv, __VA_ARGS__)
#define _glSecondaryColor3i(...) \
    callWithGLCheck(glSecondaryColor3i, __VA_ARGS__)
#define _glSecondaryColor3iv(...) \
    callWithGLCheck(glSecondaryColor3iv, __VA_ARGS__)
#define _glSecondaryColor3s(...) \
    callWithGLCheck(glSecondaryColor3s, __VA_ARGS__)
#define _glSecondaryColor3sv(...) \
    callWithGLCheck(glSecondaryColor3sv, __VA_ARGS__)
#define _glSecondaryColor3ub(...) \
    callWithGLCheck(glSecondaryColor3ub, __VA_ARGS__)
#define _glSecondaryColor3ubv(...) \
    callWithGLCheck(glSecondaryColor3ubv, __VA_ARGS__)
#define _glSecondaryColor3ui(...) \
    callWithGLCheck(glSecondaryColor3ui, __VA_ARGS__)
#define _glSecondaryColor3uiv(...) \
    callWithGLCheck(glSecondaryColor3uiv, __VA_ARGS__)
#define _glSecondaryColor3us(...) \
    callWithGLCheck(glSecondaryColor3us, __VA_ARGS__)
#define _glSecondaryColor3usv(...) \
    callWithGLCheck(glSecondaryColor3usv, __VA_ARGS__)
#define _glSecondaryColorPointer(...) \
    callWithGLCheck(glSecondaryColorPointer, __VA_ARGS__)
#define _glTexParameterIivEXT(...) \
    callWithGLCheck(glTexParameterIivEXT, __VA_ARGS__)
#define _glTexParameterIuivEXT(...) \
    callWithGLCheck(glTexParameterIuivEXT, __VA_ARGS__)
#define _glTransformFeedbackVaryingsEXT(...) \
    callWithGLCheck(glTransformFeedbackVaryingsEXT, __VA_ARGS__)
#define _glUniform1uiEXT(...) callWithGLCheck(glUniform1uiEXT, __VA_ARGS__)
#define _glUniform1uivEXT(...) callWithGLCheck(glUniform1uivEXT, __VA_ARGS__)
#define _glUniform2uiEXT(...) callWithGLCheck(glUniform2uiEXT, __VA_ARGS__)
#define _glUniform2uivEXT(...) callWithGLCheck(glUniform2uivEXT, __VA_ARGS__)
#define _glUniform3uiEXT(...) callWithGLCheck(glUniform3uiEXT, __VA_ARGS__)
#define _glUniform3uivEXT(...) callWithGLCheck(glUniform3uivEXT, __VA_ARGS__)
#define _glUniform4uiEXT(...) callWithGLCheck(glUniform4uiEXT, __VA_ARGS__)
#define _glUniform4uivEXT(...) callWithGLCheck(glUniform4uivEXT, __VA_ARGS__)
#define _glUnmapBuffer(...) callWithGLCheck(glUnmapBuffer, __VA_ARGS__)
#define _glVertexAttribI1iEXT(...) \
    callWithGLCheck(glVertexAttribI1iEXT, __VA_ARGS__)
#define _glVertexAttribI1ivEXT(...) \
    callWithGLCheck(glVertexAttribI1ivEXT, __VA_ARGS__)
#define _glVertexAttribI1uiEXT(...) \
    callWithGLCheck(glVertexAttribI1uiEXT, __VA_ARGS__)
#define _glVertexAttribI1uivEXT(...) \
    callWithGLCheck(glVertexAttribI1uivEXT, __VA_ARGS__)
#define _glVertexAttribI2iEXT(...) \
    callWithGLCheck(glVertexAttribI2iEXT, __VA_ARGS__)
#define _glVertexAttribI2ivEXT(...) \
    callWithGLCheck(glVertexAttribI2ivEXT, __VA_ARGS__)
#define _glVertexAttribI2uiEXT(...) \
    callWithGLCheck(glVertexAttribI2uiEXT, __VA_ARGS__)
#define _glVertexAttribI2uivEXT(...) \
    callWithGLCheck(glVertexAttribI2uivEXT, __VA_ARGS__)
#define _glVertexAttribI3iEXT(...) \
    callWithGLCheck(glVertexAttribI3iEXT, __VA_ARGS__)
#define _glVertexAttribI3ivEXT(...) \
    callWithGLCheck(glVertexAttribI3ivEXT, __VA_ARGS__)
#define _glVertexAttribI3uiEXT(...) \
    callWithGLCheck(glVertexAttribI3uiEXT, __VA_ARGS__)
#define _glVertexAttribI3uivEXT(...) \
    callWithGLCheck(glVertexAttribI3uivEXT, __VA_ARGS__)
#define _glVertexAttribI4bvEXT(...) \
    callWithGLCheck(glVertexAttribI4bvEXT, __VA_ARGS__)
#define _glVertexAttribI4iEXT(...) \
    callWithGLCheck(glVertexAttribI4iEXT, __VA_ARGS__)
#define _glVertexAttribI4ivEXT(...) \
    callWithGLCheck(glVertexAttribI4ivEXT, __VA_ARGS__)
#define _glVertexAttribI4svEXT(...) \
    callWithGLCheck(glVertexAttribI4svEXT, __VA_ARGS__)
#define _glVertexAttribI4ubvEXT(...) \
    callWithGLCheck(glVertexAttribI4ubvEXT, __VA_ARGS__)
#define _glVertexAttribI4uiEXT(...) \
    callWithGLCheck(glVertexAttribI4uiEXT, __VA_ARGS__)
#define _glVertexAttribI4uivEXT(...) \
    callWithGLCheck(glVertexAttribI4uivEXT, __VA_ARGS__)
#define _glVertexAttribI4usvEXT(...) \
    callWithGLCheck(glVertexAttribI4usvEXT, __VA_ARGS__)
#define _glVertexAttribIPointerEXT(...) \
    callWithGLCheck(glVertexAttribIPointerEXT, __VA_ARGS__)
#define _glWindowPos2d(...) callWithGLCheck(glWindowPos2d, __VA_ARGS__)
#define _glWindowPos2dv(...) callWithGLCheck(glWindowPos2dv, __VA_ARGS__)
#define _glWindowPos2f(...) callWithGLCheck(glWindowPos2f, __VA_ARGS__)
#define _glWindowPos2fv(...) callWithGLCheck(glWindowPos2fv, __VA_ARGS__)
#define _glWindowPos2i(...) callWithGLCheck(glWindowPos2i, __VA_ARGS__)
#define _glWindowPos2iv(...) callWithGLCheck(glWindowPos2iv, __VA_ARGS__)
#define _glWindowPos2s(...) callWithGLCheck(glWindowPos2s, __VA_ARGS__)
#define _glWindowPos2sv(...) callWithGLCheck(glWindowPos2sv, __VA_ARGS__)
#define _glWindowPos3d(...) callWithGLCheck(glWindowPos3d, __VA_ARGS__)
#define _glWindowPos3dv(...) callWithGLCheck(glWindowPos3dv, __VA_ARGS__)
#define _glWindowPos3f(...) callWithGLCheck(glWindowPos3f, __VA_ARGS__)
#define _glWindowPos3fv(...) callWithGLCheck(glWindowPos3fv, __VA_ARGS__)
#define _glWindowPos3i(...) callWithGLCheck(glWindowPos3i, __VA_ARGS__)
#define _glWindowPos3iv(...) callWithGLCheck(glWindowPos3iv, __VA_ARGS__)
#define _glWindowPos3s(...) callWithGLCheck(glWindowPos3s, __VA_ARGS__)
#define _glWindowPos3sv(...) callWithGLCheck(glWindowPos3sv, __VA_ARGS__)

#define CHECK_GL_ERROR(name)                                                   \
    {                                                                          \
        int glerror = glGetError();                                            \
        if (glerror != 0) {                                                    \
            std::cout << "\033[1;31m"                                          \
                      << "error " << glerror << " (" << glErrorString(glerror) \
                      << ") "                                                  \
                      << "in " << #name << " @ " __FILE__ << ":" << __LINE__   \
                      << "\033[0m" << std::endl;                               \
            exit(1);                                                           \
        }                                                                      \
    }

#define PRINT_GL_CONTEXT                                                       \
    {                                                                          \
        std::cout << "Context @ " << __FILE__ << ":" << __LINE__ << std::endl; \
        std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl;   \
        std::cout << "GL_SHADING_LANGUAGE_VERSION: "                           \
                  << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;    \
        std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << std::endl;     \
        std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << std::endl; \
    }

#endif  // ENGINE_GL_BRIDGE