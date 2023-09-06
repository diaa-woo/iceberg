import qrcode
img = qrcode.make('https://github.com/diaa-woo/AIoT_SerBot_PrimeX-Code')
type(img)  # qrcode.image.pil.PilImage
img.save("AIoT_Serbot.png")