// Kosmos Updater
// Copyright (C) 2019 Steven Mattera
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include "../ModalView.hpp"
#include <vector>

using namespace std;

class PasscodeView : public ModalView {
    public:
        PasscodeView();
        ~PasscodeView();

        void handleButton(u32 buttons, double dTime);
        void render(SDL_Rect rect, double dTime);

    private:
        vector<u32> _passcode;

        bool _validatePasscode();

        static inline u8 PASSCODE[] = { 0, 3, 1, 2 };
};