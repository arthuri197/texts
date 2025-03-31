from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

class Point(Structure):
    _fields_ = [("x", c_long), ("y", c_long)]  # Correção aqui: use _fields_ em vez de fields

def query_mouse_position():
    pt = Point()  # Criação da instância da estrutura Point
    windll.user32.GetCursorPos(byref(pt))  # Passa a referência de pt
    return {"x": pt.x, "y": pt.y}  # Acessa corretamente as coordenadas

if __name__ == "__main__":
    while True:
        pos = query_mouse_position()
        if pos["x"] <=799 and pos["y"] <= 449:
            print("Mouse Position: Quadrant A")

        elif pos["x"] >=800 and pos["y"] <= 449:
            print("Mouse Position: Quadrant B")
        
        elif pos["x"] <=799 and pos["y"] >= 500:
            print("Mouse Position: Quadrant C")
        
        elif pos["x"] >=800 and pos["y"] >= 500:
            print("Mouse Position: Quadrant D")
       
        time.sleep(0.1)  # Ajuste o tempo de espera conforme necessário

        if msvcrt.kbhit():
            if msvcrt.getch() == b'\x1b':  # ESC para sair (código ASCII de ESC é 27)
                break
