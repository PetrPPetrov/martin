// This is a translator from Martin programming language to C language.
// Copyright (C) 2024 Petr Petrovich Petrov
//
// This file is part of Martin translator.
//
// Martin translator is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Martin translator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Martin translator.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <string>
#include <set>
#include <vector>

struct Unterminal {
    std::string name = "????";
    std::string description = "????";
    std::vector<int> definition;
    std::set<int> first;
    std::set<int> follow;

    int rule = -1;
    int unterminal = -1;
    bool generated = false;
    bool generated_follow = false;
    int option = -1; // TODO
    std::string exclude;
};
