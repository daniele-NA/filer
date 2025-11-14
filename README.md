# Filer 📝

Welcome to **Filer**! This C application allows you to edit `.txt` files directly from your terminal. On startup, it fetches a welcome message from a **Regolo LLM** via an API call.

## Requirements ⚙️

* GCC or any compatible C compiler
* HTTP library (e.g., `libcurl`) for Regolo.ai API integration
* `.env` file in the project root with your API credentials:

  ```
  REGOLO_KEY=your_api_key_here
  URL=current_regolo_url_here
  ```

## Features ✨

* Open a `.txt` file
* Display file content
* Edit specific lines
* Save changes
* Fetch a welcome message from Regolo LLM on startup

## Compilation 🛠️

```bash
gcc -o filer main.c -lcurl
```

## Run 🚀

```bash
./filer filename.txt
```

---

**Note:** Make sure to create and configure the `.env` file before running the app, otherwise the LLM API call will fail.
