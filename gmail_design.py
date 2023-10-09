# Mail class to represent an email message
class Mail:
    def __init__(self, to, frm, sub, body):
        self.to = to
        self.frm = frm
        self.sub = sub
        self.body = body
        self.starred = False
        self.spam = False

# Global variables
userslist = []  # List to store User objects
dic = {}  # Dictionary to store user passwords
users = {}  # Dictionary to map user email IDs to User objects
presentuserid = ''  # Stores the currently logged-in user's email ID

# User class to represent a user with their email account
class User:
    def __init__(self, mailid, password):
        self.mailid = mailid
        self.password = password
        self.sentmails = []  # List to store sent emails
        self.inbox = []  # List to store received emails
        self.drafts = []  # List to store draft emails
        self.spam = []  # List to store spam emails

# Function to compose a new email
def compose(obj, to, frm, sub, body):
    newmail = Mail(to, frm, sub, body)
    ch = int(input("1.Send\t2.close"))
    if ch == 1:
        obj.sentmails.append(newmail)
        for i in range(len(to)):
            rec = users[to[i]]
            rec.inbox.append(newmail)
    elif ch == 2:
        obj.drafts.append(newmail)

# Function to display a list of emails (inbox, drafts, sent, or spam)
def display(obj, lst):
    if len(lst) != 0:
        for i in range(len(lst)):
            mail = lst[i]
            print(i, '-->', mail.sub)
        opt = int(input("1.open 2.star 3.spam 4.exit"))
        if opt == 1:
            num = int(input("Open mail number: "))
            mail = lst[num]
            print(mail.to, '\n', mail.frm, '\n', mail.sub, '\n', mail.body)
        elif opt == 2:
            num = int(input("Mail number: "))
            mail = lst[num]
            mail.starred = True
        elif opt == 3:
            num = int(input("Open mail number: "))
            mail = lst[num]
            mail.spam = True
            obj.spam.append(mail)
            obj.inbox.remove(mail)
        else:
            return
    else:
        print("NO mails")

# Function to delete all sent emails
def deletesent(obj):
    obj.sentmails.clear()

# Function to log in a user
def login(mailid):
    if mailid in dic:
        pwd = input('password')
        if dic[mailid] == pwd:
            print(presentuserid)
            return True
        else:
            print("incorrect password")
            return False
    else:
        print("Invalid user name")
        return False

# Function to create a new user
def createUser(mailid, password):
    newuser = User(mailid, password)
    userslist.append(newuser)
    dic[mailid] = password
    users[mailid] = newuser

# Function to delete a user
def deleteUser(user):
    userslist.remove(user)
    dic.pop(user.mailid)
    users.pop(user.mailid)

# Function to fill initial data (users and emails)
def filldata():
    lst1 = ['Person1@gmail.com', 'Person2@gmail.com', 'Person3@gmail.com']
    lst2 = ['123', '345', '456']
    for i in range(len(lst1)):
        createUser(lst1[i], lst2[i])

    for i in range(len(userslist)):
        usrobj = userslist[i]
        m1 = Mail([usrobj.mailid], 'design@gmail.com', 'firstmail', 'This is your first mail')
        usrobj.inbox = [m1, ]

print("GMAIL\n")
filldata()
while True:
    ch = int(input("1.Login  2.createuser 3.exit"))
    if ch == 1:
        mailid = input("enter mailid")
        ch1 = login(mailid)
        while ch1:
            presentuserid = mailid
            userobj = users[presentuserid]
            x = int(input("1.compose mail  2.display inbox  3.delete sent mails  4.display draft mails 5.display sent mails 6.display spam mails 7.logout"))
            if x == 1:
                to = list(input("TO: ").split())
                frm = presentuserid
                sub = input("subject: ")
                body = input("Body: ")
                compose(userobj, to, frm, sub, body)
            elif x == 2:
                lst = userobj.inbox
                display(userobj, lst)
            elif x == 3:
                deletesent(userobj)
            elif x == 4:
                lst = userobj.drafts
                display(userobj, lst)
            elif x == 5:
                lst = userobj.sentmails
                display(userobj, lst)
            elif x == 6:
                lst = userobj.spam
                display(userobj, lst)
            else:
                presentuserid = ''
                break
    elif ch == 2:
        mailid = input("id")
        password = input("password")
        createUser(mailid, password)
    else:
        break
