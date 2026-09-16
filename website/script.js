document.addEventListener('DOMContentLoaded', () => {
  const btn = document.querySelector('.hint-btn');
  const card = document.querySelector('.hint-card');
  if (!btn || !card) return;

  btn.addEventListener('click', () => {
    const isOpen = card.classList.toggle('is-open');
    btn.textContent = isOpen ? 'Extra hint sluiten' : 'Extra hint?';
    btn.setAttribute('aria-expanded', String(isOpen));
  });
});
