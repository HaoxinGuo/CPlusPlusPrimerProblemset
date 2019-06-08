#include "Message.h"
#include "Folder.h"

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders) // ��ÿ������m��folder
		f->addMsg(this);	 // ���Folder���һ��ָ��Message��ָ��
}

void Message::remove_from_Folders()
{
	for (auto f : folders)	// ��folders��ÿ��ָ��
		f->remMsg(this);	// �Ӹ�Folder��ɾ����Message
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders); // ʹ��set���ƶ���ֵ�����
	for (auto f : folders) {	// ����ÿ��Folder
		f->remMsg(m);			// ��Folder��ɾ����Message
		f->addMsg(this);		// ����Message��ӵ�Folder��
	}
	m->folders.clear();			// ȷ������m���޺���
}

void Message::save(Folder &f)
{
	folders.insert(&f);		// ������Folder��ӵ����ǵ�Folder�б���
	f.addMsg(this);			// ����Message��ӵ�f��Message������
}

void Message::remove(Folder &f)
{
	folders.erase(&f);		// ������Folder�����ǵ�Folder�б���ɾ��
	f.remMsg(this);			// ����Message��f��Message������ɾ��
}

//----------------------------------------------

// implement �������Ƴ�Ա

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);		// ������Ϣ��ӵ�ָ��m��Folder��
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
	move_Folders(&m);		// �ƶ�Folders������Folderָ��
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	// ͨ����ɾ��ָ���ٲ��������������Ը�ֵ�����
	remove_from_Folders();	// ��������Folder
	contents = rhs.contents;// ��rhs������Ϣ����
	folders = rhs.folders;	// ��rhs����Folderָ��
	add_to_Folders(rhs);	// ����Message��ӵ���ЩFolder��
	return *this;
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs) {		// ֱ�Ӽ���Ը�ֵ���
		remove_from_Folders();
		contents = std::move(rhs.contents); // �ƶ���ֵ�����
		move_Folders(&rhs); // ����Foldersָ��Message
	}
	return *this;
}

//----------------------------------------------

void swap(Message &lhs, Message &rhs)
{
	using std::swap;		// �ڱ������ϸ���˵������Ҫ��������һ����ϰ��
	// ��ÿ����Ϣ��ָ�������ԭ��������Folder��ɾ��
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();

	// ����contents��Folderָ��set
	swap(lhs.folders, rhs.folders);
	//swap(lhs.contents, rhs.contents); // ����contents�Ϳ������仯�ˡ���

	// ��ÿ��Message��ָ����ӵ��µ�Folder��
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}
