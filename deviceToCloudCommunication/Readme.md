# Device to Cloud Communication

Some sample code to simulate a device which is connected to the PimpMyKicker Cloud.

## Used Tutorial

http://nilhcem.com/iot/cloud-iot-core-with-the-esp32-and-arduino

## JWT Token

Extracted JWT Token for Demo Device `esp32`. Generated with Script `./certificates/main.py`

`eyJ0eXAiOiJKV1QiLCJhbGciOiJFUzI1NiJ9.eyJpYXQiOjE1OTM4NzIzMzYsImV4cCI6MTU5Mzg3NTkzNiwiYXVkIjoicGltcG15a2lja2VyIn0.XBJHada1YxAcHwyrgnT1WoprA3_pYFvOaYwWAm7eUS2RwMbZFV7gVADSihsTWGu1awCCZOo3yZOkwxeCmaa1jw`

## Sample Message

"hello PimpMyKicker" in base64: `aGVsbG8gUGltcE15S2lja2VyCg==`

## Test Message via HTTP

```
curl -X POST \
  -H 'authorization: Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJFUzI1NiJ9.eyJpYXQiOjE1OTM4NzIzMzYsImV4cCI6MTU5Mzg3NTkzNiwiYXVkIjoicGltcG15a2lja2VyIn0.XBJHada1YxAcHwyrgnT1WoprA3_pYFvOaYwWAm7eUS2RwMbZFV7gVADSihsTWGu1awCCZOo3yZOkwxeCmaa1jw' \
  -H 'content-type: application/json' \
  -H 'cache-control: no-cache' \
  --data '{"binary_data": "aGVsbG8gUGltcE15S2lja2VyCg=="}' \
  'https://cloudiotdevice.googleapis.com/v1/projects/pimpmykicker/locations/europe-west1/registries/iotcore-registry/devices/esp32:publishEvent'
{}
```
