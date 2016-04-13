#pragma once
#include <string>
#include <set>
#include <algorithm>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string &str = ""):contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder *f) { folders.insert(f); }
    void remFolder(Folder *f) { folders.erase(f); }
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder
{
    friend void swap(Folder&, Folder&);
public:
    explicit Folder(const std::string &str = ""):title(str){}
    Folder(const Folder&);
    void addMsg(Message *m) { messages.insert(m); };
    void remMsg(Message *m) { messages.erase(m); };
    Folder& operator=(const Folder&);
    ~Folder();
private:
    std::string title;
    std::set<Message*> messages;
    void add_to_Messages(const Folder &);
    void remove_from_Messages();
};

Folder::Folder(const Folder &f):messages(f.messages)
{
    for (auto m : messages)
    {
        m->folders.insert(this);
    }
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages)
        m->addFolder(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : messages)
        m->remFolder(this);
    messages.clear();
}

Folder& Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}


void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) :contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
    folders.clear();
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    for (auto f : lhs.folders)
    {
        f->remMsg(&lhs);
    }

    for (auto f : rhs.folders)
    {
        f->remMsg(&rhs);
    }

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}