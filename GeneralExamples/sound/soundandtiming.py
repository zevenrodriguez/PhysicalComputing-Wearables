import board
import digitalio
import time

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

wave_file = open("cow.wav", "rb")
wave = WaveFile(wave_file)
audio = AudioOut(board.SPEAKER)

playOnce = False

startTime = time.monotonic()
interval = 10

while True:

    # Playing sound in a loop
    #if audio.playing == False:
    #    audio.play(wave)

    # Playing sound once
    #if playOnce == False:
    #    playOnce = True
    #    audio.play(wave)

    # Playing sound over an interval
    #if time.monotonic() - startTime > interval:
    #    startTime = time.monotonic()
    #    audio.play(wave)


    print(audio.playing)
    time.sleep(0.01)
