/*
 * md2.h
 *
 *  Created on: 23/12/2010
 *      Author: felipe
 */

#ifndef MD2_H_
#define MD2_H_

struct MD2Header {
	int id;
	int version;
	int skinWidth;
	int skinHeight;
	int frameSize;
	int numSkins;
	int numVertices;
	int numTextureCoord;
	int numTriangles;
	int numGLCmds;
	int numFrames;
	int skinOffset;
	int textCoordOffset;
	int triangleOffset;
	int frameOffset;
	int GLCmdOffset;
	int EOFOffset;
};

struct Skin {
	char name[64];
};

struct TextCoord {
	short s;
	short t;
};

struct Triangle {
	short vertexIndex[3];
	short texCoordIndex[3];
};

struct Vertex {
	unsigned char v[3];
	unsigned char lightNormalIndex;
};

struct KeyFrame {
	float scale[3];
	float translate[3];
	char name[16];
	struct Vertex *vertices;
};

struct MD2Data {
	struct MD2Header header;
	struct Skin *skins;
	struct TextCoord *texcoords;
	struct Triangle *triangles;
	struct KeyFrame *frames;
};
#endif /* MD2_H_ */
