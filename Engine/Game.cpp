/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "ResourceLocator.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	link({ 100, 100 }, {0, 0}, 90, 90, 1.5f, GetResource("link90x90.bmp")),
	consolas(GetResource("Consolas13x24.bmp"), 3, 32),
	fixedSys(GetResource("Fixedsys16x28.bmp"), 3, 32)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		link.SetDirection({ 0, -1 });
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		link.SetDirection({ 0, 1 });
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		link.SetDirection({ -1, 0 });
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		link.SetDirection({ 1, 0 });
	}
	else {
		link.SetDirection({ 0, 0 });
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		link.ActivateDamadgeEffect();
		hit.Play();
	}
	link.Update( frameTimer.Mark() );
}

void Game::ComposeFrame()
{
	consolas.DrawText({ 200, 200 }, "Dushbag \nHello!", gfx);
	fixedSys.DrawText({ 400, 400 }, "Hello asdas adsas asd \nasas aasdas asdsa!", gfx);
	link.Draw(gfx);
}
