import * as functions from "firebase-functions";
import * as admin from "firebase-admin";

admin.initializeApp();
export const firestore = admin.firestore();

export const pubSubToFirestore = functions.pubsub
  .topic("iotcore-topic")
  .onPublish(async (message, context) => {
    console.log(context.eventId);
    let messageBody = "undefined";
    try {
      messageBody = message.data
        ? Buffer.from(message.data, "base64").toString()
        : "could not decode";
    } catch (e) {
      messageBody = e.message || "no error message";
    }
    await firestore.collection("match").add({ messageBody });
  });
