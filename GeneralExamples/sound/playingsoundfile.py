import board
import digitalio

try:
    from audiocore import WaveFile
except ImportError:
    from audioio import WaveFile

try:
    from audioio import AudioOut
except ImportError:
    try:
        from audiopwmio import PWMAudioOut as AudioOut
    except ImportError:
        pass  # not always supported by every board!

# Enable the speaker
spkrenable = digitalio.DigitalInOut(board.SPEAKER_ENABLE)
spkrenable.direction = digitalio.Direction.OUTPUT
spkrenable.value = True

# BUTTON_A is an reference to the 2 buttons on the Circuit Python Express
switch = digitalio.DigitalInOut(board.BUTTON_A)
switch.direction = digitalio.Direction.INPUT

# pull controls the electrical behavoir of the pin
# The standard Pull.DOWN as electricity flows through the pin, switch.value = False(LOW), When the button is pressed, switch.value = True(HIGH)
switch.pull = digitalio.Pull.DOWN

wasPressed = False # Keeps track of the last time button was pressed

wave_file = open("cow.wav", "rb")
wave = WaveFile(wave_file)
audio = AudioOut(board.SPEAKER)

while True:
    if switch.value == True:
        wasPressed = True # Keeps track that the button is pressed
    else:
        # This is the state when the button is de-pressed
        # Check if the button was pressed in the past
        if wasPressed == True:
            wasPressed = False
            audio.play(wave)


