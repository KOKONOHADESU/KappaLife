#include "SceneResult.h"
#include "SceneMain.h"

#include <DxLib.h>

SceneResult::SceneResult()
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
}

void SceneResult::End()
{
	
}

SceneBase* SceneResult::Update()
{
	
	return new SceneMain();
}

void SceneResult::Draw()
{

}
