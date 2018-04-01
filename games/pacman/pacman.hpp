//
// Created by rectoria on 06/03/18.
//

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "IGameLib.hpp"

namespace Arcade {
	class Pacman : public Arcade::IGameLib {
	public:
		Pacman() = default;

		~Pacman() final = default;

	public:
		/* Get the name of the game */
		const std::string &getName() const final;

		/* Resources handling */
		// Initializes the library
		bool init() final;

		// Unloads the library
		bool stop() final;

		// Closes the game => stop loop (go menu)
		bool close() final;

		// Opens the game => start loop
		bool open() final;

		// Processes the key obtained by the IGraphicLib from the user to update the game state
		void applyEvent(Arcade::Keys) final;

		// Updates the game state. (Move the player forward and/or move the NPCs)
		void update() final;

		// Renders the game state to the screen. This should call IGraphicLib::refresh() to display content to the user.
		void refresh(Arcade::IGraphicLib *) final;

	private:
		std::string _name = "Pacman";
	};
}
#endif
