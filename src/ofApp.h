#pragma once

#include "ofMain.h"

#include <wchar.h>
#include <direct.h>

#include<string>
#include<iostream> 
#include<fstream> 
#include<sstream>

#include "pxccapture.h"
#include "pxcsensemanager.h"
#include "pxccapturemanager.h"
#include "pxchandcursormodule.h"
#include "pxccursordata.h"
#include "pxchandconfiguration.h"
#include "pxchanddata.h"
#include "pxchandmodule.h"
#include "pxcfacemodule.h"
#include "pxcfaceconfiguration.h"
#include "pxcprojection.h"

#include "ofxImGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//Visual Creole�S�̂�State�B�N������̃v���W�F�N�g�I���A�^��A�ҏW�̂R��
		enum _VC_State {
			ENTRY, //�N������͂���B
			RECORD,
			EDIT
		} ;

		_VC_State VC_State;

		//�^���ʂł̃X�e�[�g
		enum R_State {
			WAITING, //
			READY,	//
			RECORDING,//�^�撆�A���̎��ɂ͉摜�̕`������Ȃ��ł���Ƃ悢�H
			RECORDED //�^��I�����B�����ҏW��ʂɑJ�ڂ���
		} ;
		/*

		/*
		points 
		�̂̃p�[�c���ꂼ��̏��i����̂Ђ�A�E��l�����w��Aetc�j
		dP[n]�Ƃ��Đ錾�B
		�֋X��w�i�̕����ϐ����m�ۂ��Ă����ienable�͏��true�j
		�Ăѕ��� dP[lEye].pos.x �Ȃǁi���ڂ�x���W���擾�j
		�擾�_�𑝂₷�Ƃ��́A#define�őΉ�����ď̂��`���邱�ƁB
		*/

		typedef struct _point {
			bool en;//��Ƃ������m����āA�l���X�V�\�ł������Ƃ���true
			char* name;//���O������Bofapp.cpp��setup�ōs���Ă���͂�
			ofVec2f pos;//���W
		} point;
	
#define dPsize 8

		point dP[dPsize];

	#define lHandPalm	0
	#define lHandTip	1
	#define rHandPalm	2
	#define rHandTip	3
	#define lEye		4
	#define rEye		5
	#define mouse		6
	#define bg			7

		typedef struct _lenderunit {
			bool en;
			int to;
			ofFbo layer; //�h���[�C���O���e��ۑ����Ă����B�ύX�������̂݁A���̃��C�����摜������B
			ofImage image; //layer���摜���������́A������e�h���[�|�C���g�i�w��etc�j�ɒǏ]�����\������B
			ofImage fileimg; //�O������ǂݍ��񂾉摜�t�@�C��
			ofVec2f offset;
			int size; //%��Blayer�����fileimg��
			int size_pre; //�T�C�Y�ύX�����m���邽�߁A1�t���O�̑傫��������Ă����܂�
			//for future work
			int in, out; //�`��L���A�����ƂȂ�t���[��
		} lenderunit;

#define lunitsize 4

		lenderunit lunit[lunitsize]; //�ЂƂ܂����E�̎�A��A�w�i�Ɏg����悤��4�m��

		ofFbo mainlayer; //�ŏI�I�ɂ��̃��C���ɂ��ׂĂ�lenderunit.image���܂Ƃ߂ď������ށB

		void initializeRSSDK();
		void initializeLoadedValue();

		void updateCamera();

		void drawPoints();
		void drawImages();
		void drawPicCtrl();

		ofxImGui::Gui gui;
};
