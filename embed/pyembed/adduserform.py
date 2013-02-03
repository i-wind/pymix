from Tkinter import *

# The root window manager object
root = Tk()
root.title("New User")

# Memory attached to the three text input fields
sv_fname = StringVar(); #first name
sv_lname = StringVar(); #last name
sv_email = StringVar(); #email

# Data of a new user is returned to the C++ environment
# inside this dictionary. The pyembed C++ library
# converts this to a std::map<string, string>
data_map = {'FirstName' : '', 'LastName' : '', 'Email' : ''}

# turned on when ok button is clicked
ok_clicked = 0

# Callback to the "Ok" button
def ok():
    global ok_clicked
    data_map['FirstName'] = sv_fname.get();
    data_map['LastName'] = sv_lname.get();
    data_map['Email'] = sv_email.get();
    ok_clicked = 1
    root.destroy()

# Callback to the "Cancel" button
def cancel():
    global ok_clicked
    data_map['FirstName'] = ''
    data_map['LastName'] = ''
    data_map['Email'] = ''
    ok_clicked = 0
    root.destroy()

# Creates and displays the UI
# C++ application calls this function.
# Returns the dictionary of the newley create user
# or an empty dictionary of one item if the user
# clicked cancel
def show_win():    
    top = Frame(root)
    top.grid()
            
    fname_label = Label(top, width = 15, text = 'First Name:')
    fname_label.grid(row = 0)
    sv_fname.set('')
    fname_entry = Entry(top, width = 25, relief = 'groove',
                    textvariable = sv_fname)
    fname_entry.grid(row = 0, column = 1, sticky = W)

    lname_label = Label(top, width = 15, text = 'Last Name:')
    lname_label.grid(row = 1)
    sv_lname.set('')
    lname_entry = Entry(top, width = 25, relief = 'groove',
                    textvariable = sv_lname)
    lname_entry.grid(row = 1, column = 1, sticky = W)

    email_label = Label(top, width = 15, text = 'Email:')
    email_label.grid(row = 2)
    sv_email.set('')
    email_entry = Entry(top, width = 40, relief = 'groove',
                    textvariable = sv_email)
    email_entry.grid(row = 2, column = 1, sticky = W)

    button_panel = Frame(top)
    button_panel.grid(row = 3, column = 1)
    ok_button = Button(button_panel, text = 'Ok', command = ok)
    ok_button.pack(side = 'left')
    cancel_button = Button(button_panel, text = 'Cancel', command = cancel)
    cancel_button.pack(side = 'left')
    
    root.mainloop()
    return get_data()

# Helper to show_ui()
# checks the state of ok_clicked and
# returns an appropriate dictionary
def get_data():
    if ok_clicked == 1:        
        return data_map
    else:        
        return {"" : ""}

    

