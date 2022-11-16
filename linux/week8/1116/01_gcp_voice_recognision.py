from google.cloud import speech
import io

# 사용할 파일 path
file_path = '/home/pi'

# Instantiates a client
client = speech.SpeechClient()

# 리퀘스트 구성
config = speech.RecognitionConfig(
    encoding = speech.RecognitionConfig.AudioEncoding.LINEAR16,
    sample_rate_hertz = 48000,
    language_code = "ko-KR" #영어는 en-US
)

# 파일 열기 - 바이너리(오디오 데이터) 읽기 모드
with io.open(file_path, "rb") as f:
    voice_data = f.read()
audio = speech.RecognitionAudio(content = voice_data);

# 리퀘스트 보내고 응답 받아온다
response = client.recognize(config = config, audio = audio)

# results 는 음성이 잠시 멈출 때로 구분되는 여러개의 세그먼트의 리스트
# (한 문장 ~= 한 세그먼트)
for result in response.results:
    print(f"Transcript: { result.alternatives[0].transcrip }")