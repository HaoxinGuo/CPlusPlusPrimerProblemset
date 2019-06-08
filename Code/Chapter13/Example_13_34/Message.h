#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);

public:
	// folders����ʽ��ʼ��Ϊ�ռ���
	explicit Message(const std::string &str = "") :
		contents(str) {}

	// �������Ƴ�Ա����������ָ��Message��ָ��
	Message(const Message&);			// �������캯��
	Message(Message&&);					// �ƶ����캯��
	Message& operator=(const Message&);	// ������ֵ�����
	Message& operator=(Message&&);		// �ƶ���ֵ�����
	~Message();							// ��������

	// �Ӹ���Folder���������/ɾ����Message
	void save(Folder&);
	void remove(Folder&);


private:
	std::string contents;		// ʵ����Ϣ�ı�
	std::set<Folder*> folders;	// ������Message��Folder

	// �������캯����������ֵ�����������������ʹ�õĹ��ߺ���
	// ����Message��ӵ�ָ�������Folder��
	void add_to_Folders(const Message&);

	// ��folders�е�ÿ��Folder��ɾ����Message
	void remove_from_Folders();

	// �ӱ�Message�ƶ�Folderָ��
	void move_Folders(Message *m);
};

#endif // MESSAGE_H
