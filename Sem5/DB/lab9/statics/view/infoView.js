import { show_docs } from "../model/util/dataUtil.js";
import { render_main } from "./mainView.js";

export default function render(data) {
    let root = document.body;
    root.innerHTML = "";
    let btn_back = document.createElement("button");
    btn_back.textContent = "Назад";
    btn_back.addEventListener("click", render_main);
    let div_info = document.createElement("div");
    div_info.id = "info";
    root.appendChild(btn_back);
    root.appendChild(div_info);
    show_docs(data);
}