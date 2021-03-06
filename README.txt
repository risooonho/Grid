GRID
Main developer : Marc Gilleron
marc.gilleron@free.fr
README last update : 21/01/2012 22:43

Description :

	Grid is a cross-platform 2D shooter game project.
	You spawn in a world, and you have to explore it and defending yourself.
	In the current version, there is no real purpose in the game
	(it will come later). It includes a level editor, which is the same for
	designers and players.
	
	IMPORTANT:
	The project isn't in development anymore, but some parts of it may be useful
	for further projects.

Planned features :

	see main.cpp.

Download releases :
	
	2012/01/21 - Windows 7 32-bits
	http://www.mediafire.com/?ez7s7f1953sfkwv
	
	These releases are rapidly tested, and may work on the specified platorms.
	However, they are not official releases and may contain bugs.

Download development resources :
	
	All items that are not included in the repo can be downloaded here :

	- Resource files 
		<TODO host files...>
		
	- Libraries
		SFML 1.6 :
			http://www.sfml-dev.org/download.php
		Lua 5.1.4 + Lunar :
			http://sourceforge.net/projects/luabinaries/files/5.1.4/Windows%20Libraries/
			http://lua-users.org/wiki/CppBindingWithLunar
	
How to compile :

	Grid is written in C++ and can compile with MinGW (tested).
	The IDE I currently use is Code::Blocks
	(but you can use another one if you find the way to configure it).
	
	Project dependencies :

		* SFML 1.6
			-lsfml-audio
			-lsfml-graphics
			-lsfml-window
			-lsfml-system
			
		* Lua 5.1.4, with the Lunar extension
		
		WARNING : I am not currently sure about keeping this language.
			Another candidate I'm testing is AngelScript, because Lua
			doesn't support enough paradigms for OOP.
	
	Binary dependencies :
	
		* sfml-audio
		* sfml-graphics
		* sfml-network
		* sfml-system
		* sfml-window
		* openal32
		* libsndfile-1
		* libgcc_s_dw2 (introduced by SFML 1.6)
		* lua5.1
	
	Game resources :
	
		The game include several audio/image/postfx/library files
		that are not included in the repo. You should find them in
		the 'development resources' section.
		
		Note : under Code::Blocks, to run and debug the project,
		the default directory for loading files is the same as the *.cbp.
		You must copy resources files at this point, or configure Code::Blocks
		in order to set it relative to the binary executable.

Project's files structure :
	
	src/ : source files       | These have the same sub-folder hierarchy
	include/ : header files   |
	
	utility :
		Global-purpose functions and classes.
		dependencies : SFML (not for all) and Lua (can be easily removed)
		
	gui :
		Simple GUI classes.
		dependencies : SFML (not for all)
	
	game :
		Sources related to the game.
		dependencies : utility/ and gui/
		
	game/base :
		Base classes of the game.
		It is developped around an entity-based structure.
	
	game/components :
		Components.
	
	game/entities :
		Entities.
		
	game/items :
		Items.
	
	game/renderers :
		Renderers (basically, all the drawing stuff)
				
Project's code conventions :

	Naming :

		class names and types are written as this :
			WithUpperCaseLettersAtWordsBeginning.
		
		functions and variable names are written the same,
			but theFirstLetterIsInLowerCase.

		Prefixing :

			m_ : private or protected class-member.
				 Public members are not prefixed.
			     If it is a pointer, it must be deleted after use.
				 
			r_ : private or protected class-member reference,
				 or pointer used as a reference.
				 There is no memory management to perform with these variables.
				 
			p_ : Function parameter (optional). Use it in case of conflict.

			g_ : global variable (ONLY in implementation files).
			
			s_ : static variable

		Each file containing one class has the same name for header and source.
		If there is more classes, the file has the name of the main class or
		main class group.
		if a file do not contains any class, its name begins with a
		lower case character.
		The project can have header-only files.

	Indentation :

		Size : 4 spaces, all braces-aligned format (ANSI).
		some exceptions can be done for very small,
		huge block combinations or too long lines.
		exception : no indentation before "public", "protected" or
		"private" keywords.

	Margin :

		the margin is set to 100 characters.
		If a line is too large, please split it.

	Comments :
		
		FIXME: known or potential bug to fix
		TODO : task to do, removed when done.
			   Global tasks are placed in main.cpp.
		SUGG : suggestion
		NOTE : note
		
		// Comment on one line
		
		/* Code section in functions or class defs */
		
		/*
			Huge code section between function or class defs (global space)
		*/
		
		/** Strong comments are reserved for documentation only. **/
		
	
