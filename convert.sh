for f in *.mp3 *.flac *.acc 
do
   sox $f -c 1 -r 8000 -e unsigned-integer -b 8 $f.wav
done
