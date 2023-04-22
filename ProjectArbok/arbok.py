
import pyotp
import base64
import qrcode
import hmac
import os


def generateQR(user: str, password: str):
    img = qrcode.make("otpauth://totp/project_arbok?secret="+base64.b32encode((user+password).encode()).decode())
    img.save("qr.png")

def verifyTOTP(user: str, password: str, totp: int):
    TOTP = pyotp.TOTP(base64.b32encode((user+password).encode()))
    return TOTP.verify(totp)

def createUser(user: str, password: str):
    if not ".cuentas" in os.listdir():
            os.mkdir(".cuentas")
    hmac1 = hmac.new(user.encode(), password.encode(), "sha256").digest()
    with open(f".cuentas/{user}.txt", "wb") as handler:
        handler.write(hmac1)
    generateQR(user, password)

def verifyUser(user: str, password: str):
    try:
        with open(f".cuentas/{user}.txt", "rb") as handler:
            hmac1 = handler.read()
        hmac2 = hmac.new(user.encode(), password.encode(), "sha256").digest()
        return hmac.compare_digest(hmac1, hmac2)
    except:
         return False

