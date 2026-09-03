import mongoose from "mongoose";
import constants from "../../constants.js";

const connectDB = async () => {
    try {
        const conn = await mongoose.connect(`${process.env.MONGO_URI}/${constants.DB_NAME}`)
        console.log(`MongoDB Connected Successfully: ${conn.connection.host}`)
    } catch (error) {
        console.log(`Error: ${error.message}`)
    }
}

export default connectDB;