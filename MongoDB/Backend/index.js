// run hone waali main file

import dotenv from "dotenv";
import connectDB from "./src/db/db.js";
import app from "./app.js";

dotenv.config({ path: ".env" });

await connectDB();

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
