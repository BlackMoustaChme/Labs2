class BigBell:
    def __init__(self):
        self.soundwave = True

    def sound(self):
        if self.soundwave == True:
            print("ding")
            self.soundwave = False
        else:
            print("dong")
            self.soundwave = True


bell = BigBell()
bell.sound()
bell.sound()
bell.sound()
