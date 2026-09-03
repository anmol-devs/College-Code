// run hone waali main file

import dotenv from "dotenv";
import cors from "cors";
import connectDB from "./src/db/db.js";
import app from "./app.js";

connectDB();
dotenv.config();