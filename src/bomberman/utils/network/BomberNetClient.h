#include <SDL2/SDL.h>
#ifndef IS_OSX
#include <SDL2/SDL_net.h>
#else
#include <SDL2_net/SDL_net.h>
#endif
#include "../GameConfig.h"

#ifndef __MYCLASS_BOMBERNETCLIENT
#define __MYCLASS_BOMBERNETCLIENT

#define GAME_PORT			7777
#define GAME_BYE			255
#define GAME_MAXPEOPLE		2

class BomberNetClient {
	public:
		static BomberNetClient& Instance();
		static TCPsocket tcpsock;
		static SDLNet_SocketSet socketset;

		BomberNetClient();
		~BomberNetClient();

		void sendLine();
		void createTcpClient();
		bool connectClient();
		void disconnectClient();

	private:
		static BomberNetClient m_instance;

		//server thread
		static bool alive;
		static int net_thread_main(void *data);
		SDL_Thread *net_thread;


		BomberNetClient& operator=(const BomberNetClient&);
		BomberNetClient(const BomberNetClient&);
		void initSDLNet();
		void allocateSocket();
		bool isAlive();
		void cleanup();
		void handleNet();

};
#endif
