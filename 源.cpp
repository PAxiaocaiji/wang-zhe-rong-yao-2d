void  Helloworld::connectServer() {
	ODSocket  cSocket :

	cSocket.Init();
	cSocket.Create(AF - INET, SOCK - STREAM, 0);

	const char* ip = ��111.11.11.111��;
	Int port = 7777;

	bool  result = cSocket.Connect(ip, port);
	If(result) {
		Log(��connect to server suc !��);
	}

	   else {
	   log(��can not connect to server ��);
		  }
}//���ӷ�����




 public  class  Serve {
	Public static void main(String[] args) {
		ServerSocket  ss = null;
		ClientThread  cilentThread = new ClientThread();
		Try{
			ss = new ServerSocket(7777);
			clientThread.start();
		}
			catch (Exception  e) {
		}

		System.out.println(����������ʼ��);
		While(true) {
			Try{
			   Socket  so = ss.accept();
			 if (so = null) {
				   Continue;
}
					 System.out.println(���ͻ��������ӡ�����
					 clientThread,addClient(so);
						 }
						 catch (IOException  e) {
							 e.printStackTrace();
						 }
		}
	}
}
		 }//�����


		 Public  class ClientThread   extends  Thread {
			 Private  ArrayList<Socket> clients = new ArrayList<Socket>();


			 Public void addClient(Socket  so) {
				 Clients.add(so);
				 putputStream  os;
				 try {
					 os = so.getOutputStream();
					 String  send = ��\��cmd\��:1
				 }��;
				 os.write(send.getBytes(��UTF - 8))��
					 ��catch(IOException  e) {
				 }
			 }//���͵�¼��Ϣ

			 Public void run() {
				 while (true) {
					 try {
						 for (Socket so : clients) {
							 InputStream  is = so.getInputStream();
							 int len = is.available();
							 if (len <= 0) {
								 continue;
							 }
							 byte[] buff = new byte[len];
							 Is.read(buff);

							 String read = new String(buff);
							 System.out.println(�����յ������ݣ��� + read);
						 }
						 Sleep(10);
					 }
					 catch (IOException e) {
					 }
					 catch (InterruptedException  e) {
					 }
				 }
			 }
		 }//���ܿͻ�����

#include �� cocos2d.h��
#include ��ODSocket\ODSocket.h��
		 USING_NS_CC;

#define  MAX_LEN  512
		 Class SocketManager : public Ref{
		 public:
			SocketManager();
	   ~SocketManager();
		static SocketManager* getInstance();
	   CREATE_FUNC(SocketManager);
		virtual bool init();

		void start();
		void sentMsg(const char* msg);
	   private:
			static SocketManager* m_SocketManager;

			ODSocket  csocket;
			bool  connectServer();
			void  recvData();
		 };
#endif//���ݴ���






