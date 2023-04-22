import tkinter as tk
from PIL import ImageTk, Image

# Función para verificar las credenciales del usuario
def authenticate():
    # Verificamos si el usuario y la contraseña son válidos
    # Si es así, permitimos el acceso a la aplicación
    # Si no, mostramos un mensaje de error
    pass

# Función para registrar un nuevo usuario
def register():
    # Creamos una nueva entrada para el usuario y la contraseña en el archivo de almacenamiento
    pass


# Creamos la ventana principal
root = tk.Tk()
root.title("Autenticación de usuario")

# Cargamos la imagen del logo de 42Malaga
# logo = Image.open("42Malaga_logo.png")
# logo = logo.resize((150, 150), Image.ANTIALIAS)
# logo = ImageTk.PhotoImage(logo)

# Agregamos el logo a la ventana principal
# logo_label = tk.Label(image=logo)
# logo_label.image = logo
# logo_label.pack()

# Creamos etiquetas y campos de entrada de texto para el usuario y la contraseña
user_label = tk.Label(root, text="Usuario:")
user_entry = tk.Entry(root)
password_label = tk.Label(root, text="Contraseña:")
password_entry = tk.Entry(root, show="*")

# Agregamos las etiquetas y campos de entrada de texto a la ventana principal
user_label.pack()
user_entry.pack()
password_label.pack()
password_entry.pack()

# Creamos los botones de inicio de sesión y registro
login_button = tk.Button(root, text="Iniciar sesión", command=authenticate)
register_button = tk.Button(root, text="Registrar usuario", command=register)

# Agregamos los botones a la ventana principal
login_button.pack()
register_button.pack()

# Creamos una etiqueta para mostrar mensajes al usuario
message_label = tk.Label(root, text="")
message_label.pack()
